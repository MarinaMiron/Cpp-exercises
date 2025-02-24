#include <iostream>
using namespace std;
#include "Product.hpp"
#include <memory>
#include <vector>

#ifndef CUSTOMER_H //ensuring that this object is only initialized once
#define CUSTOMER_H 

using namespace std;

class Customer
{
private:
    std::string name;
    std::string email;
    std::vector<std::shared_ptr<Product>> cart;
public:
    Customer(/* args */);
    ~Customer();
};

#endif