#include <iostream>
using namespace std;

#include <string>
#include "../include/Product.hpp"
#include "../include/Laptop.hpp"

Laptop::Laptop(std::string name, double price, int stock, std::string category, int id, 
    int ram, std::string processor, int storage, std::string gpu)
{
    this->name = name;
    this->price = price;
    this->stock = stock;
    this->category = category;
    this->id = id;
    this->ram = ram;
    this->processor = processor;
    this->storage = storage;
    this->gpu = gpu;
    cout << "Laptop object created" << endl;
}
Laptop::Laptop()
{
    cout << "Laptop object created without parameters" << endl;
}
Laptop::~Laptop()
{
    cout << "Laptop object deleted" << endl;
}

int Laptop::getRam()
{
    return ram;
}

std::string Laptop::getProcessor()
{
    return processor;
}

int Laptop::getStorage()
{
    return storage;
}

std::string Laptop::getGpu()
{
    return gpu;
}