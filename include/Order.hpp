#include <iostream>
#include "Customer.hpp"
using namespace std;

#include <vector>
#include <memory>

#ifndef ORDER_H //ensuring that this object is only initialized once
#define ORDER_H
using namespace std;
class Order
{
private:
    int orderId;
    std::vector<std::shared_ptr<Product>> products;
    double totalPrice;
    std::shared_ptr<Customer> customer;
    std::string status;

public:
    Order(/* args */);
    ~Order();
};

#endif