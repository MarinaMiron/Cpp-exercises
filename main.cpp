#include <iostream>
using namespace std;

#include <vector>

#include "include/Factory.hpp"
#include "include/Customer.hpp"
#include "include/Order.hpp"
#include "include/Store.hpp"

int main()
{   
    Store& store = Store::getInstance(); // unique instance for Store

    // 1. Adding observers to notify low stock
    store.addStockObserver([](const Product& product) {
        std::cout << "ALERT: Low stock for " << product.getName() << " (ID: " 
                  << product.getId() << "). Only " << product.getStock() << " left!\n";
    });

    // 2. Registering clients
    std::shared_ptr<Customer> customer1 = std::make_shared<Customer>(1, "Alex Popescu", "alex@email.com");
    std::shared_ptr<Customer> customer2 = std::make_shared<Customer>(2, "Maria Ionescu", "maria@email.com");

    store.registerCustomer(customer1);
    store.registerCustomer(customer2);

    // 3. Addind products to store
    ProductFactory factory;

    std::shared_ptr<Product> laptop = factory.createProduct<Laptop>("Dell XPS 15", 7500.0, 2, "Laptop", 102, 16, "Intel Core i7", 512, "NVIDIA RTX 3050");
    std::shared_ptr<Product> phone = factory.createProduct<Smartphone>("iPhone 15", 5000.0, 10, "Smartphone", 201, "iOS", 6.1, 4000, true);
    std::shared_ptr<Product> watch = factory.createProduct<Smartwatch>("Apple Watch", 2000.0, 1, "Smartwatch", 301, "Apple", true, 1.5, 24);

    store.addProduct(laptop);  // ALERT: Low stock (stoc = 2)
    store.addProduct(phone);
    store.addProduct(watch);   // ALERT: Low stock (stoc = 1)

    // 4. Printing store inventory
    store.printInventory();

    // 5. Filter products under 5000 RON
    std::vector<std::shared_ptr<Product>> cheapProducts = store.filterProducts(
        [](const std::shared_ptr<Product>& product) { return product->getPrice() < 5000.0; }
    );

    std::cout << "\n Products under 5000 RON:\n";
    for (const auto& product : cheapProducts) {
        std::cout << "- " << product->getName() << " (" << product->getPrice() << " RON)\n";
    }

    // 6. Apply a 10% discount on laptops
    store.applyDiscount([](std::shared_ptr<Product>& product) {
        if (product->getCategory() == "Laptop") {
            double newPrice = product->getPrice() * 0.9;
            product->setPrice(newPrice);
            std::cout << "Discount applied to " << product->getName() << ": New price = " << newPrice << " RON\n";
        }
    });

    // 7. The clients add products to their carts
    customer1->addToCart(laptop);
    customer1->addToCart(phone);
    customer2->addToCart(watch);

    // 8. Placing orders
    std::shared_ptr<Order> order1 = std::make_shared<Order>(1001, customer1->getCart(), customer1);
    store.placeOrder(order1);

    std::shared_ptr<Order> order2 = std::make_shared<Order>(1002, customer2->getCart(), customer2);
    store.placeOrder(order2); // ALERT: Low stock (stock = 0 for Apple Watch)

    // 9. Printing all orders
    store.printOrders();

    // 10. Changing the status of an order
    store.updateOrderStatus(1001, "shipped");

    // 11. Showing the best selling product
    std::shared_ptr<Product> bestSelling = store.getBestSellingProduct();
    if (bestSelling) {
        std::cout << "\nBest-selling product: " << bestSelling->getName() << " (" << bestSelling->getPrice() << " RON)\n";
    }

    // 12. Calculating total revenue
    std::cout << "Total revenue: " << store.calculateTotalRevenue() << " RON\n";

    return 0;
}