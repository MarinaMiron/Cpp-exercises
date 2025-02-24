#include <iostream>
using namespace std;

#include <string>
#include "../include/Product.hpp"
#include "../include/Smartphone.hpp"

Smartphone::Smartphone(std::string name, double price, int stock, std::string category, int id,
    std::string os, double screenSize, int battery, bool has5G)
{   
    this->name = name;
    this->price = price;
    this->stock = stock;
    this->category = category;
    this->id = id;
    this->os = os;
    this->screenSize = screenSize;
    this->battery = battery;
    this->has5G = has5G;
    cout << "Smartphone object created" << endl;
}

Smartphone::Smartphone()
{
    cout << "Smartphone object created without parameters" << endl;
}

Smartphone::~Smartphone()
{
    cout << "Smartphone object deleted" << endl;
}

std::string Smartphone::getOs()
{
    return os;
}

double Smartphone::getScreenSize()
{
    return screenSize;
}

int Smartphone::getBattery()
{
    return battery;
}

bool Smartphone::getHas5G()
{
    return has5G;
}