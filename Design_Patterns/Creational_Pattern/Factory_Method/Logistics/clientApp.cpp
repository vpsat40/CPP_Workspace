/**
 * @file clientApp.cpp
 * @author SatishV
 * @brief 
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "iLogisticsFactory.h"

void clientCode(const iLogisticsFactory& Logistics)
{
    std::cout << "I am unaware of who is going to transport my goods."
                << " But I am sure it will be delivered... \n"
                << Logistics.planDelivery() << std::endl;
}


int main()
{
    std::cout << "App: Launched with Truck Transport... \n";
    iLogisticsFactory* landLogistics = new RoadLogistics();
    clientCode(*landLogistics);
    std::cout << "-----------------" << std::endl;

    std::cout << "App: Launched with Sea Transport... \n";
    iLogisticsFactory* seaLogistics = new SeaLogistics();
    clientCode(*seaLogistics);
    std::cout << "-----------------" << std::endl;

    delete landLogistics;
    delete seaLogistics;
    return 0;
}