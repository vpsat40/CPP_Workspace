/**
 * @file iTransportFactory.h
 * @author Satish V
 * @brief 
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <iostream>

/**
 * @brief Create a tansport factory interface that allows creation of
 * concrete transport products (Eg: Truck, Shipping, Flight) classes.
 * 
 */

class iTransportFactory 
{
    public:
    virtual ~iTransportFactory() {}
    virtual std::string deliverGoods() const = 0;
};

/**
 * @brief Create a TruckFactory transport
 * 
 */

class TruckFactory : public iTransportFactory
{
    public:
    std::string deliverGoods() const override
    {
        return "Transporting/Delivering goods via land using Trucks \n";
    }

};

class ShipFactory : public iTransportFactory
{
    public:
    std::string deliverGoods() const override
    {
        return "Transporting/Delivering goods via sea using Shipping Containers \n";
    }
};