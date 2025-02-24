#ifndef SMARTPHONE_H 
#define SMARTPHONE_H 

#include <iostream>
using namespace std;

#include <string>
#include "Product.hpp"

class Smartphone : public Product
{
private:
    std::string os;
    double screenSize;
    int battery;
    bool has5G;

public:
    Smartphone(std::string name, double price, int stock, std::string category, int id,
        std::string os, double screenSize, int battery, bool has5G);
    Smartphone();
    ~Smartphone();
    
    std::string getOs();
    double getScreenSize();
    int getBattery();
    bool getHas5G();
};
#endif