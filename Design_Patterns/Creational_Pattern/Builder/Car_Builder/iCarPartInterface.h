/**
 * @file iCarPartInterface.h
 * @author Satish V
 * @brief 
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <iostream>
#include <vector>

/**
 * @brief Car is a complex machine. I makes sense to use builder pattern
 * to configure the kind of car you build.
 * 
 */

class Toyota
{
    public:
    std::vector<std::string> _carModules;

    void ListCarModules() const
    {
        std::cout << "This car consists of : " << std::endl;

        for(auto itr = _carModules.begin(); itr != _carModules.end(); ++itr)
        {
            std::cout << *itr << std::endl;
        }
    }
};