#include "../include/Factory.hpp"
#include <iostream>

ProductFactory::ProductFactory() {
    // Implementarea constructorului
}

std::unique_ptr<Product> ProductFactory::createProduct(const std::string& type) 
{
    if (type == "Laptop") {
        return std::make_unique<Laptop>();
    } else if (type == "Smartphone") {
        return std::make_unique<Smartphone>();
    } else if (type == "Smartwatch") {
        return std::make_unique<Smartwatch>();
    }
    return nullptr;
}