#include <iostream>
using namespace std;

#include <vector>

#include "include/Factory.hpp"
#include "include/Customer.hpp"
#include "include/Order.hpp"
// #include "include/Store.hpp"

int main()
{   
    //ProductFactory* prod1 = new LaptopFactory("Asus ROG", 1299.99, 5, "Electronics", 101, 16, "Intel i7", 512, "NVIDIA RTX 3060");
    ProductFactory factory;

    auto laptop = factory.createProduct<Laptop>("Asus ROG", 1299.99, 5, "Electronics", 101, 16, "Intel i7", 512, "NVIDIA RTX 3060");
    auto phone = factory.createProduct<Smartphone>( "Samsung Galaxy S23", 4800.0, 8, "Smartphone", 202, "Android", 6.1, 3900, true);

    Customer customer = Customer(1, "Alex Popescu", "alex@email.com");

    customer.addToCart(laptop);
    customer.addToCart(phone);

    Order order(1001, customer.getCart(), std::make_shared<Customer>(customer));

    order.printOrderDetails();

    order.updateStatus("shipped");
    std::cout << "New Status: " << order.getStatus() << "\n";

    //cout << "Programul a rulat cu succes. Ura! " << endl;
    
    return 0;
}