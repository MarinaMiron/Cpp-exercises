#include <iostream>
using namespace std;

#include <string>
#include <algorithm>
#include "../include/Product.hpp"
#include "../include/Store.hpp"
#include "../include/Order.hpp"
#include "../include/Customer.hpp"

Store::Store()
{
    cout << "Store created" << endl;
}

Store::~Store()
{
    cout << "Store deleted"  << endl;
}

Store& Store::getInstance()
{
    static Store instance;
    return instance;
}

void Store::addProduct(std::shared_ptr<Product> product)
{
    if (!product) {
        std::cout << "Error: Cannot add a null product to the store.\n";
        return;
    }

    int productId = product->getId();  // Get product ID

    // Verifies if product is already in inventory
    if (inventory.find(productId) != inventory.end()) {
        std::cout << "Product with ID " << productId << " already exists in the store.\n";
        return;
    }

    // Adds product to inventory
    inventory[productId] = product;
    std::cout << "Added product: " << product->getName() << " (ID: " << productId << ") to the store.\n";

    // Notifies the observers if the stock is low
    if (product->getStock() < 3) {
        notifyStockObservers(*product);
    }
}

void Store::removeProduct(int productId)
{
    auto product = inventory.find(productId);
    if (product == inventory.end()) {
        std::cout << "Product with ID " << productId << " not found in store.\n";
        return;
    }

    inventory.erase(product);
    std::cout << "Product with ID " << productId << " was removed from the store the store.\n";
    return;
}

std::shared_ptr<Product> Store::findProduct(int productId) const
{
    auto product = inventory.find(productId);
    if (product != inventory.end()) {
        return product->second;  // Return found product
    }

    std::cout << "Product with ID " << productId << " not found in store.\n";
    return nullptr;
}

std::vector<std::shared_ptr<Product>> Store::filterProducts(std::function<bool(const std::shared_ptr<Product>&)> criteria) const
{
    std::vector<std::shared_ptr<Product>> result;

    for (const auto& pair : inventory) {
        if (criteria(pair.second)) {
            result.push_back(pair.second);
        }
    }

    return result;
    
}

void Store::applyDiscount(std::function<void(std::shared_ptr<Product>&)> discountFunction)
{
    for (auto& pair : inventory) {
        discountFunction(pair.second);
    }
}

void Store::placeOrder(std::shared_ptr<Order> order)
{
    if (!order) {
        std::cout << "Error: Cannot place a null order.\n";
        return;
    }

    int orderId = order->getOrderId();
    if (findOrder(orderId)) {
        std::cout << "Order with ID " << orderId << " already exists.\n";
        return;
    }

    orders.push_back(order);
    std::cout << "Order ID " << orderId << " has been placed successfully.\n";

    //Verifies stock after sell
    for (const auto& product : order->getProducts()) {
        if (product->getStock() < 3) {
            notifyStockObservers(*product);
        }
    }
}

std::shared_ptr<Order> Store::findOrder(int orderId) const
{
    auto order = std::find_if(orders.begin(), orders.end(),
    [orderId](const std::shared_ptr<Order>& order) {
        return order->getOrderId() == orderId;
    });

    return (order != orders.end()) ? *order : nullptr;
}

void Store::updateOrderStatus(int orderId, const std::string& newStatus)
{
    std::shared_ptr<Order> order = findOrder(orderId);
    if (!order) {
        std::cout << "Order ID " << orderId << " not found.\n";
        return;
    }

    order->updateStatus(newStatus);
    std::cout << "Order ID " << orderId << " status updated to: " << newStatus << ".\n";
}

std::vector<std::shared_ptr<Order>> Store::getOrdersByCustomer(int customerId) const
{
    std::vector<std::shared_ptr<Order>> customerOrders;

    for (const auto& order : orders) {
        if (order->getCustomer()->getId() == customerId) {
            customerOrders.push_back(order);
        }
    }

    return customerOrders;
}

void Store::registerCustomer(std::shared_ptr<Customer> customer)
{
    if (!customer) {
        std::cout << "Error: Cannot register a null customer.\n";
        return;
    }

    int customerId = customer->getId();

    if (customerExists(customerId)) {
        std::cout << "Customer with ID " << customerId << " already exists.\n";
        return;
    }

    customers[customerId] = customer;
    std::cout << "Customer " << customer->getName() << " (ID: " << customerId << ") has been registered.\n";
}

std::shared_ptr<Customer> Store::findCustomer(int customerId) const
{
    auto customer = customers.find(customerId);
    if (customer != customers.end()) {
        return customer->second;
    }

    std::cout << "Customer with ID " << customerId << " not found.\n";
    return nullptr;
}

bool Store::customerExists(int customerId) const
{
    return customers.find(customerId) != customers.end();
}


void Store::printInventory() const
{
    if (inventory.empty()) {
        std::cout << "No products available.\n";
        return;
    }

    std::cout << "All products:\n";
    for (const auto& pair : inventory) {
        const auto& product = pair.second;
        std::cout << "ID: " << product->getId()
                  << ", Name: " << product->getName()
                  << ", Price: " << product->getPrice() << " RON"
                  << ", Stock: " << product->getStock() << "\n";
    }
}

void Store::printOrders() const
{
    if (orders.empty()) {
        std::cout << "No orders available.\n";
        return;
    }

    std::cout << "All orders:\n";
    for (const auto& order : orders) {
        order->printOrderDetails();
        std::cout << "-----------------------\n";
    }
}

void Store::printCustomers() const
{
    if (customers.empty()) {
        std::cout << "No customers registered.\n";
        return;
    }

    std::cout << "Registered customers:\n";
    for (const auto& pair : customers) {
        std::cout << "ID: " << pair.first << ", Name: " << pair.second->getName() << ", Email: " << pair.second->getEmail() << "\n";
    }
}

std::shared_ptr<Product> Store::getBestSellingProduct() const
{
    if (orders.empty()) {
        std::cout << "No orders placed yet.\n";
        return nullptr;
    }

    std::unordered_map<int, int> productSales; // Map [productId -> number of sales]

    // Iterating through all the orders to see the sell rate of products
    for (const auto& order : orders) {
        for (const auto& product : order->getProducts()) {
            productSales[product->getId()]++;
        }
    }

    // Finding the product with the most sales
    int bestSellingProductId = -1;
    int maxSales = 0;

    for (const auto& pair : productSales) {
        if (pair.second > maxSales) {
            maxSales = pair.second;
            bestSellingProductId = pair.first;
        }
    }

    if (bestSellingProductId == -1) {
        std::cout << "No best-selling product found.\n";
        return nullptr;
    }

    return findProduct(bestSellingProductId);
}

double Store::calculateTotalRevenue() const
{
    if (orders.empty()) {
        return 0.0;
    }

    double totalRevenue = 0.0;

    for (const auto& order : orders) {
        totalRevenue += order->calculateTotal();
    }

    return totalRevenue;
}

void Store::addStockObserver(std::function<void(const Product&)> observer) 
{
    stockObservers.push_back(observer);
}

void Store::notifyStockObservers(const Product& product) const {
    for (const auto& observer : stockObservers) {
        observer(product);
    }
}