#ifndef ORDER_H
#define ORDER_H

using namespace std;
#include <iostream>
#include "Customer.hpp"
using namespace std;

#include <vector>
#include <memory>

class Order
{
private:
    int orderId;
    std::vector<std::shared_ptr<Product>> products;
    double totalPrice;
    std::shared_ptr<Customer> customer;
    std::string status;

public:
    Order(int orderId, std::vector<std::shared_ptr<Product>> products, std::shared_ptr<Customer> customer);
    ~Order();

    double calculateTotal() const;
    std::string getStatus() const;
    void updateStatus(const std::string &new_status);
    void printOrderDetails() const;
};
#endif