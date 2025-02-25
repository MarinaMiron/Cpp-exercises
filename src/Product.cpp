#include <iostream>
using namespace std;

#include <string>
#include "../include/Product.hpp"

Product::Product(std::string name, double price, int stock, std::string category, int id)
{
    this->name = name;
    this->price = price;
    this->stock = stock;
    this->category = category;
    this->id = id;
}

Product::Product()
{
}

// Product::~Product()
// {
//     cout << "Destructor called\n" << endl;
// }

std::string Product::getName() const
{ 
    return name; 
}

double Product::getPrice() const
{ 
    return price; 
}
    
int Product::getStock() const 
{ 
    return stock; 
}

std::string Product::getCategory() const 
{ 
    return category;
}

int Product::getId() const 
{ 
    return id; 
}

void Product::setPrice(double newPrice)
{
    price = newPrice;
}