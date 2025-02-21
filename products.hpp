#include <iostream>
#include <studio.h>
using namespace std;

#include <vector>

class Product
{   
private:
    std::string name;
    double price;
    int stock;
    std::string category;
    int id;

public:
    virtual ~Product() = default;

    virtual std::string getName() const { return name; }
    virtual double getPrice() const { return price; }
    virtual int getStock() const { return stock; }
    virtual std::string getCategory() const { return category; }
    virtual int getId() const { return id; }

    // Reducere stoc
    virtual void reduceStock(int quantity) {
        if (quantity <= stock) stock -= quantity;
    }

    // Funcție pur virtuală pentru afisare detalii
    virtual void display() const = 0;
};



class Laptop : public Product
{
private:
    int ram;              
    std::string processor; 
    int storage;
    std::string gpu

public:
    Laptop(/* args */);
    ~Laptop();
};

Laptop::Laptop(/* args */)
{
}

Laptop::~Laptop()
{
}

class Smartphone : public Product
{
private:
    std::string os;
    double screenSize;
    int battery;
    bool has5G;

public:
    Smartphone(/* args */);
    ~Smartphone();
};

Smartphone::Smartphone(/* args */)
{
}

Smartphone::~Smartphone()
{
}

class Smartwatch : public Product
{
private:
    std::string brand;
    bool isWaterproof;
    double screenSize;
    int battery;
    
public:
    Smartwatch(/* args */);
    ~Smartwatch();
};

Smartwatch::Smartwatch(/* args */)
{
}

Smartwatch::~Smartwatch()
{
}