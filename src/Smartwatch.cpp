#include <iostream>
using namespace std;

#include <string>
#include "../include/Product.hpp"
#include "../include/Smartwatch.hpp"

Smartwatch::Smartwatch(std::string name, double price, int stock, std::string category, int id, 
    std::string brand, bool isWaterproof, double screenSize, int battery)
{
    this->name = name;
    this->price = price;
    this->stock = stock;
    this->category = category;
    this->id = id;
    this->brand = brand;
    this->isWaterproof = isWaterproof;
    this->screenSize = screenSize;
    this->battery = battery;
    cout << "Smartwatch object created" << endl;
}
Smartwatch::Smartwatch()
{
    cout << "Smartwatch object created without parameters" << endl;
}
Smartwatch::~Smartwatch()
{
    cout << "Smartwatch object deleted" << endl;
}

std::string Smartwatch::getBrand()
{
    return brand;
}

bool Smartwatch::getIsWaterproof()
{
    return isWaterproof;
}

double Smartwatch::getScreenSize()
{
    return screenSize;
}

int Smartwatch::getBattery()
{
    return battery;
}