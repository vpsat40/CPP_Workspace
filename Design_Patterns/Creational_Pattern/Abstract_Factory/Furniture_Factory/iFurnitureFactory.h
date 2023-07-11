/**
 * @file iFurnitureFactory.h
 * @author SatishV
 * @brief 
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "iChairProduct.h"
#include "iTableProduct.h"

/**
 * @brief The Furniture Factory interface delares a set of methods that return
 * different abstract furniture variants. These variants are called a family and are 
 * related by a hig-level theme or concept (Eg: Victorian, Modern, Art).  
 * Furnitureof one family are uusally able to collaborate among themselves.
 * A family of furniture may have several variants (Eg: chair, table, sofa...), 
 * but the furniture of one variant are incompatible with Furniture of another.
 * 
 */

class iFurnitureFactory
{
    public:
    virtual iChairInterface *createChairs() const = 0;  //(AbstractProductA)
    virtual iTableInterface *createTables() const = 0;  //(AbstractProductB)

};

/**
 * @brief Concrete factories produce family of products that belong to a single
 * variant. The factory guarantees that resulting products are compatible. 
 * Note that signature of the Concrete Factory's methods return an abstract product,
 * while inside the method a concrete product is instantiated.
 * 
 */
class VictorianFurnitureFactory : public iFurnitureFactory
{
    public:
    iChairInterface *createChairs() const override
    {
        return new VictorianChair();
    }

    iTableInterface *createTables() const override
    {
        return new VictorianTable();
    }
};

class ModernFurnitureFactory : public iFurnitureFactory
{
    public:
    iChairInterface *createChairs() const override
    {
        return new ModernChair();
    }

    iTableInterface *createTables() const override
    {
        return new ModernTable();
    }
};