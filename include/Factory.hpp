#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>
#include <string>

#include "../include/Product.hpp"
#include "../include/Laptop.hpp"
#include "../include/Smartphone.hpp"
#include "../include/Smartwatch.hpp"

class ProductFactory
{
    public:
        ProductFactory();
        std::unique_ptr<Product> createProduct(const std::string& type);
};
#endif