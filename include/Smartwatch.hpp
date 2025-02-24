#ifndef SMARTWATCH_H
#define SMARTWATCH_H 

#include <iostream>
using namespace std;

#include <string>
#include "Product.hpp"

class Smartwatch : public Product
{
private:
    std::string brand;
    bool isWaterproof;
    double screenSize;
    int battery;

public:
    Smartwatch(std::string name, double price, int stock, std::string category, int id, 
    std::string brand, bool isWaterproof, double screenSize, int battery);
    Smartwatch();
    ~Smartwatch();
    
    std::string getBrand();
    bool getIsWaterproof();
    double getScreenSize();
    int getBattery();
};



#endif