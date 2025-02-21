#include <iostream>
#include <studio.h>
using namespace std;

#include <vector>

class Order
{
private:
    int orderId;
    std::vector<std::shared_ptr<Product>> products;
    double totalPrice;
    std::shared_ptr<Customer> customer;

public:
    Order(/* args */);
    ~Order();
};

Order::Order(/* args */)
{
}

Order::~Order()
{
}