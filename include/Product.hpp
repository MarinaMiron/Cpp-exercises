#ifndef PRODUCT_H
#define PRODUCT_H 

#include <iostream>
using namespace std;

#include <string>

class Product
{   
protected:
    std::string name;
    double price;
    int stock;
    std::string category;
    int id;

public:
    virtual ~Product() 
    {
        cout << "Destructor called\n" << endl;
    };
    Product();
    Product(std::string name, double price, int stock, std::string category, int id);

    std::string getName() const;
    double getPrice() const;
    int getStock() const;
    std::string getCategory() const;
    int getId() const;

    void setPrice(double newPrice);
};
#endif