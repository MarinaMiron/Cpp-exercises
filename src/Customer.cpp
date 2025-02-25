#include <iostream>
using namespace std;
#include <numeric>
#include <algorithm>
#include <string>
#include "../include/Product.hpp"
#include "../include/Customer.hpp"

Customer::Customer()
{
    cout << "Customer created" << endl;
}
Customer::Customer(int id, std::string name, std::string email)
{   
    this->id = id;
    this->name = name;
    this->email = email;
    cout << "Customer " << name << " created" << endl;

}
Customer::~Customer()
{
    cout<< "Customer deleted" << endl;
}

void Customer::addToCart(std::shared_ptr<Product> product)
{
    cart.push_back(product);
}

void Customer::removeFromCart(std::shared_ptr<Product> product)
{
    cart.erase(std::remove_if(cart.begin(), cart.end(),
            [&](const std::shared_ptr<Product>& p) 
            {
                return p == product;
            }),
            cart.end());
}

const std::vector<std::shared_ptr<Product>>& Customer::getCart() const 
{
    return cart;
}

std::string Customer::getName() const
{
    return name;
}

int Customer::getId() const
{
    return id;
}

std::string Customer::getEmail() const
{
    return email;
}

double Customer::calculateCartTotal() const
{
   return std::accumulate(cart.begin(), cart.end(), 00.0,
    [](double total, const std::shared_ptr<Product>& product) 
    {
        return total + product->getPrice();
    });
}

void Customer::printCartTotal() const 
{
    std::cout << "Cart Total: " << calculateCartTotal() << " RON\n";
}