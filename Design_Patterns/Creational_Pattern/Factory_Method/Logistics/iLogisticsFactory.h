/**
 * @file iLogisticsFactory.h
 * @author SatishV
 * @brief 
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "iTransportFactory.h"

/**
 * @brief The Logistics class contains the factory method which retruns an
 * object of specific Transport class. The Logistics class can provide a 
 * default implementation of the factory method.
 * 
 */

class iLogisticsFactory
{
    public:
    virtual ~iLogisticsFactory() {}

    /**
     * @brief This is the Factory Method. A default implementation of the 
     * Tansport object can beimplemented here
     * 
     * @return iTransportFactory* 
     */
    virtual iTransportFactory* createTransport() const = 0;

    /**
     * @brief iLogisticsFactory class's primary responsibility is not to create
     * Transport objects. Usually, it contains some core buisiness logic that 
     * relies on Transport objects, returned by the factory method. Subclasses
     * can indirectly change the buisiness logic by overriding the factory method
     * and return a different type of Transport object from it.
     */

    std::string planDelivery() const
    {
        // Call the factory method to create a Transport object
        iTransportFactory* transportType = this->createTransport();

        // Now you can use the created tranport type to send goods
        std::string result = "Goods ready for delivery. " + transportType->deliverGoods();
        delete transportType;
        return result;
    }
};

class RoadLogistics : public iLogisticsFactory
{
    /**
     * @brief Note that the signature of the Factory method (createTransport) still
     * uses the abstract Transport type (iTransportFactory), even though a concrete
     * Transport (Truch/Ship) is returned by the method.
     * 
     */

    public:
    iTransportFactory* createTransport() const override
    {
        return new TruckFactory();
    }
};

class SeaLogistics : public iLogisticsFactory
{
    public:
    iTransportFactory* createTransport() const override
    {
        return new ShipFactory();
    }
};