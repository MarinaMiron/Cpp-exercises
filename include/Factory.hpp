#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "../include/Product.hpp"
#include "../include/Laptop.hpp"
#include "../include/Smartphone.hpp"
#include "../include/Smartwatch.hpp"

class ProductFactory
{
    public:
        template<typename T, typename... Args>
        std::unique_ptr<T> createProduct(Args&&... args)
        {
            return std::make_unique<T>(std::forward<Args>(args)...);
        };
};
#endif