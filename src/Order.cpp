#include <iostream>
using namespace std;

#include <numeric>
#include <string>
#include "../include/Product.hpp"
#include "../include/Order.hpp"

Order::Order(int orderId, std::vector<std::shared_ptr<Product>> products, std::shared_ptr<Customer> customer)
{
    this->orderId = orderId;
    this->products = products;
    this->customer = customer;
    status = "Pending";
    totalPrice = calculateTotal();
}
Order::~Order()
{
    cout << "Order deleted";
}

double Order::calculateTotal() const
{
    return std::accumulate(products.begin(), products.end(), 00.0,
    [](double total, const std::shared_ptr<Product>& product) 
    {
        return total + product->getPrice();
    });
}

std::string Order::getStatus() const
{
    return status;
}

int Order::getOrderId() const
{
    return orderId;
}

std::shared_ptr<Customer> Order::getCustomer() const
{
    return customer;
}

std::vector<std::shared_ptr<Product>> Order::getProducts() const
{
    return products;
}

void Order::updateStatus(const std::string &newStatus)
{
    status = newStatus;
}

void Order::printOrderDetails() const
{
    std::cout << "Order ID: " << orderId << "\n";
    std::cout << "Customer: " << customer->getName() << "\n";
    std::cout << "Products:\n";
    for (const auto& product : products) 
    {
        std::cout << "  - " << product->getName() << " (" << product->getPrice() << " RON)\n";
    }
    std::cout << "Total Price: " << totalPrice << " RON\n";
    std::cout << "Status: " << status << "\n";
}