/**
 * @file clientApp.cpp
 * @author SatishV
 * @brief 
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "iFurnitureFactory.h"

/**
 * @brief The client Application works with Factories and products only through
 * abstract types: AbstractFactory and AbstractProduct. This lets you pass any
 * factory or product subclass to the client application without breaking it.
 * 
 */

void ClientApp(const iFurnitureFactory &factory)
{
    const iChairInterface *product_a = factory.createChairs();
    const iTableInterface *product_b = factory.createTables();

    std::cout << product_b->looklike() << std::endl;
    std::cout << product_b->compatibleWith(*product_a) << std::endl;
    std::cout << product_a->sittinOn() << std::endl;

    delete product_a;
    delete product_b;
}


int main()
{
    std::cout << "Client: Testing client application with Victorian Factory type: \n";
    VictorianFurnitureFactory *vFactory = new VictorianFurnitureFactory();
    ClientApp(*vFactory);
    delete vFactory;

    std::cout << "\nClient: Testing client application with Modern Factory type: \n";
    ModernFurnitureFactory *mFactory = new ModernFurnitureFactory();
    ClientApp(*mFactory);
    delete mFactory;

}
