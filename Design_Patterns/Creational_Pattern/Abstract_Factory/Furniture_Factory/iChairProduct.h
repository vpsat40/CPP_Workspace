/**
 * @file iChairProduct.h
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

/**
 * @brief Each distinct chair of a chair family should have a base chair interface.
 * All variants of the chair must implement this base chair interface.  * 
 */

class iChairInterface
{
public:
    virtual ~iChairInterface() {};
    virtual std::string sittinOn() const = 0;
    virtual std::string haslegs() const = 0;

};

/**
 * @brief Concrete chair products are created by corresponding factories. 
 * Question to contemplate. Are interfaces being named as factories here??
 */

class VictorianChair : public iChairInterface
{
    public:    
    std::string sittinOn() const override
    {
        return "I am sitting on a Victorian Chair. He he";
    }

    std::string haslegs() const override
    {
        return "A Victorian Chair. It has 4 strong wooden legs";
    }
};

class ModernChair : public iChairInterface
{
    public:
    std::string sittinOn() const override
    {
        return "I am sitting on a Modern Chair. Hmm";
    }
    
    std::string haslegs() const override
    {
        return "A Modern chair. It has no legs. Its base is made of mould plastic...";
    }
};