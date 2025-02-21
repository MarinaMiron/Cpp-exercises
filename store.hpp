#include <iostream>
#include <studio.h>
using namespace std;

#include <vector>

class Store
{
private:
    static std::shared_ptr<Store> instance;
    std::unordered_map<int, std::shared_ptr<Product>> products;

    Store() {}
public:
    Store(/* args */);
    ~Store();
};

Store::Store(/* args */)
{
}

Store::~Store()
{
}