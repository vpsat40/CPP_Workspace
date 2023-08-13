/**
 * @file iBuilderInterface.h
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
 * Use Builder pattern only when your products are quite complex and require 
 * extensive configuration.
 *
 * Unlike in other creational patterns, different concrete builders can produce
 * unrelated products. In other words, various concrete builders may not
 * always follow the same interface.
 */

class Product1
{
    public:
    std::vector<std::string> parts_;
    void ListParts()const
    {
        std::cout << "Product parts: ";
        for (size_t i=0;i<parts_.size();i++)
        {
            if(parts_[i]== parts_.back())
            {
                std::cout << parts_[i];
            }
            else
            {
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n"; 
    }
};

/**
 * The Builder interface specifies methods for creating the different parts of
 * the Product objects.
 */
class Builder
{
    public:
    virtual ~Builder(){}
    virtual void ProducePartA() const =0;
    virtual void ProducePartB() const =0;
    virtual void ProducePartC() const =0;
};

/**
 * The Concrete Builder classes follow the Builder interface and provide
 * specific implementations of the building steps. Your program may have several
 * variations of Builders, implemented differently.
 */
class ConcreteBuilder1 : public Builder
{
    private:
    Product1* product;

    /**
     * A fresh builder instance should contain a blank product object, which is
     * used in further assembly.
     */
    public:

    ConcreteBuilder1()
    {
        this->Reset();
    }

    ~ConcreteBuilder1()
    {
        delete product;
    }

    void Reset()
    {
        this->product= new Product1();
    }

      /**
     * All production steps work with the same product instance.
     */

    void ProducePartA()const override
    {
        this->product->parts_.push_back("PartA1");
    }

    void ProducePartB()const override
    {
        this->product->parts_.push_back("PartB1");
    }

    void ProducePartC()const override
    {
        this->product->parts_.push_back("PartC1");
    }

    /**
     * Concrete Builders are supposed to provide their own methods for
     * retrieving results. That's because various types of builders may create
     * entirely different products that don't follow the same interface.
     *
     * Usually, after returning the end result to the client, a builder instance
     * is expected to be ready to start producing another product. That's why
     * it's a usual practice to call the reset method at the end of the
     * `getProduct` method body. However, this behavior is not mandatory, and
     * you can make your builders wait for an explicit reset call from the
     * client code before disposing of the previous result.
     */

    /**
     * Please be careful here with the memory ownership. Once you call
     * GetProduct the user of this function is responsable to release this
     * memory. Here could be a better option to use smart pointers to avoid
     * memory leaks
     */

    Product1* GetProduct() 
    {
        Product1* result= this->product;
        this->Reset();
        return result;
    }
};

