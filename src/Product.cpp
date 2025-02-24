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

std::string Product::getName()
{ 
    return name; 
}

double Product::getPrice()
{ 
    return price; 
}
    
int Product::getStock() 
{ 
    return stock; 
}

std::string Product::getCategory() 
{ 
    return category;
}

int Product::getId() 
{ 
    return id; 
}