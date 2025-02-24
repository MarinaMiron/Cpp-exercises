#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
using namespace std;

#include <string>
#include "Product.hpp"

class Laptop : public Product
{
private:
	int ram;
	std::string processor;
	int storage;
	std::string gpu;

public:
	Laptop(std::string name, double price, int stock, std::string category, int id,
	       int ram, std::string processor, int storage, std::string gpu);
	Laptop();
	~Laptop();

    int getRam();
    std::string getProcessor();
    int getStorage();
    std::string getGpu();
};
#endif