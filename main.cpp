#include <iostream>
using namespace std;

#include <vector>

#include "include/Factory.hpp"
#include "include/Customer.hpp"
// #include "include/Order.hpp"
// #include "include/Store.hpp"

int main()
{   
    //ProductFactory* prod1 = new LaptopFactory("Asus ROG", 1299.99, 5, "Electronics", 101, 16, "Intel i7", 512, "NVIDIA RTX 3060");
    ProductFactory factory;

    auto laptop = factory.createProduct<Laptop>("Asus ROG", 1299.99, 5, "Electronics", 101, 16, "Intel i7", 512, "NVIDIA RTX 3060");
    auto phone = factory.createProduct<Smartphone>( "Samsung Galaxy S23", 4800.0, 8, "Smartphone", 202, "Android", 6.1, 3900, true);

    Customer customer;
    customer.addToCart(laptop);
    customer.addToCart(phone);
    customer.printCartTotal(); // Output: Total cos: 11000 RON

    customer.removeFromCart(laptop);
    customer.printCartTotal(); // Output: Total cos: 5000 RON

    cout << "Programul a rulat cu succes. Ura! " << endl;
    
    return 0;
}