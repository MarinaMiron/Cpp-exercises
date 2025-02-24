#include <iostream>
using namespace std;

#include <vector>

#include "include/Factory.hpp"
// #include "include/Customer.hpp"
// #include "include/Order.hpp"
// #include "include/Store.hpp"

int main()
{   
    //ProductFactory* prod1 = new LaptopFactory("Asus ROG", 1299.99, 5, "Electronics", 101, 16, "Intel i7", 512, "NVIDIA RTX 3060");
    ProductFactory factory;
    auto laptop = factory.createProduct("laptop");
    // ProductFactory* prod2 = new SmartphoneFactory();
    // ProductFactory* prod3 = new SmartwatchFactory();
    // std::cout << prod1->getName() << std::endl;
    // delete factory;
    // delete laptop;
    // delete prod2;
    // delete prod3;
    cout << "Programul a rulat cu succes!" << endl;
    
    return 0;
}