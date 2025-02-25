#include <iostream>
using namespace std;
#include "Product.hpp"
#include <memory>
#include <vector>

#ifndef CUSTOMER_H
#define CUSTOMER_H 

using namespace std;

class Customer
{
private:
    int id;
    std::string name;
    std::string email;
    std::vector<std::shared_ptr<Product>> cart;
public:
    Customer();
    Customer(int id, std::string name, std::string email);
    ~Customer();

    void addToCart(std::shared_ptr<Product> product);
    void removeFromCart(std::shared_ptr<Product> product_id);
    const std::vector<std::shared_ptr<Product>>& getCart() const;
    std::string getName() const;
    int getId() const;
    std::string getEmail() const;
    double calculateCartTotal() const;
    void printCartTotal() const;
};

#endif