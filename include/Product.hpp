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

    std::string getName();
    double getPrice();
    int getStock();
    std::string getCategory();
    int getId();


    // Funcție pur virtuală pentru afisare detalii
    //virtual void display() const = 0;
};
#endif