#ifndef STORE_H
#define STORE_H 

#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>
#include <memory>
#include <unordered_map>
#include "Product.hpp"
#include "Order.hpp"
#include "Customer.hpp"
#include <functional>

class Store
{
private:
    static std::shared_ptr<Store> instance;
    std::unordered_map<int, std::shared_ptr<Product>> inventory;
    std::vector<std::shared_ptr<Order>> orders;
    std::unordered_map<int, std::shared_ptr<Customer>> customers;

    Store(); 

    Store(const Store&) = delete;
    Store& operator=(const Store&) = delete;

    std::vector<std::function<void(const Product&)>> stockObservers;

public:
    ~Store();
    static Store& getInstance();

    void addProduct(std::shared_ptr<Product> product);
    void removeProduct(int productId);
    std::shared_ptr<Product> findProduct(int productId) const;
    std::vector<std::shared_ptr<Product>> filterProducts(std::function<bool(const std::shared_ptr<Product>&)> criteria) const;
    void applyDiscount(std::function<void(std::shared_ptr<Product>&)> discountFunction);

    void placeOrder(std::shared_ptr<Order> order);
    std::shared_ptr<Order> findOrder(int orderId) const;
    void updateOrderStatus(int orderId, const std::string& newStatus);
    std::vector<std::shared_ptr<Order>> getOrdersByCustomer(int customerId) const;

    void registerCustomer(std::shared_ptr<Customer> customer);
    std::shared_ptr<Customer> findCustomer(int customerId) const;
    bool customerExists(int customerId) const;

    void printInventory() const;
    void printOrders() const;
    void printCustomers() const;
    std::shared_ptr<Product> getBestSellingProduct() const;
    double calculateTotalRevenue() const;

    void addStockObserver(std::function<void(const Product&)> observer);
    void notifyStockObservers(const Product& product) const;

};
#endif