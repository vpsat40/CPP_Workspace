/**
 * @file iTableProduct.htmlonly 
 * @endhtmlonly
 * 
 * @author SatishV 
 * @brief 
 * @version 0.1
 * @date 2023-07-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <iostream>
#include "iChairProduct.h"

/**
 * @brief Here's the base interface of Table product. All tables can interact 
 * with each other, but proper interaction is possible only between products of 
 * the same concrete variant. * 
 */

class iTableInterface
{
    public:
    virtual ~iTableInterface() {};
    virtual std::string looklike() const = 0;

    /**
     * In addition to being a table interace..
     * 
     * ... I can also collaborate with iChair interface.
     * 
     * The Abstract Factory makes sure that all furniture it creates are
     * of the same kind and are thus compatible...
     */

    virtual std::string compatibleWith(const iChairInterface &collaborator) const = 0;
    
};

class VictorianTable : public iTableInterface
{
    public:
    std::string looklike() const override
    {
        return "I am a Victorian Table.";
    }

    /**
     * @brief The Victorian table variant is only able to work correctly with a 
     * Victorian Chair. Nevertheless, it accepts any instance of iChairInterface 
     * as an argument.
     * 
     */

    std::string compatibleWith(const iChairInterface &collaborator) const override
    {
        const std::string result = collaborator.haslegs();
        return " A Victorian Table is compatible with - " + result;
    }
};

class ModernTable : public iTableInterface
{
    public:
    std::string looklike() const override
    {
        return "I am a Mondern Table.";
    }

    /**
     * @brief The Victorian table variant is only able to work correctly with a 
     * Victorian Chair. Nevertheless, it accepts any instance of iChairInterface 
     * as an argument.
     * 
     */

    std::string compatibleWith(const iChairInterface &collaborator) const override
    {
        const std::string result = collaborator.haslegs();
        return " A Modern Table is compatible with - " + result;
    }
};