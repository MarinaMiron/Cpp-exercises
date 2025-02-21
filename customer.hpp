#include <iostream>
#include <studio.h>
using namespace std;

#include <vector>

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

Customer::Customer(/* args */)
{
}

Customer::~Customer()
{
}