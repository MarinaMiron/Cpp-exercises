#include <iostream>
using namespace std;

#include <vector>
#include <set>
#include <memory>
#include <unordered_map>
#include "Product.hpp"
#include "Order.hpp"
#include "Customer.hpp"

#ifndef STORE_H //ensuring that this object is only initialized once
#define STORE_H 

class Store
{
private:
    static std::shared_ptr<Store> instance;
    std::unordered_map<int, std::shared_ptr<Product>> products;
    std::vector<std::shared_ptr<Order>> orders;
    std::set<std::shared_ptr<Customer>> customers;

public:
    Store(/* args */);
    ~Store();
};

#endif