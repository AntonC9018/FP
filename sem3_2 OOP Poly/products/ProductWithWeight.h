#pragma once
#include <string>
#include <iostream>
#include "./Product.h"



class ProductWithWeight : public virtual Product
{
private:
    int m_weight;
    std::string m_unit;

protected:
    ProductWithWeight(int weight, const std::string &unit)
        : m_weight(weight),
          m_unit(unit) {}

public:
    ProductWithWeight() = default;

    ProductWithWeight(const ProductBaseParams &params,
                      int weight,
                      const std::string &unit)
        : Product(params),
          m_weight(weight),
          m_unit(unit) {}

    void PromptInputAll() override
    {
        Product::PromptInputAll();
        PromptInputSpecific();
    }

    void PromptInputSpecific()
    {
        std::cout << "Enter weight: ";
        std::cin >> m_weight;
        std::cout << "Enter unit: ";
        std::cin >> m_unit;
    }

    void PrintAll() const override
    {
        Product::PrintAll();
        PrintSpecific();
    }

    void PrintSpecific() const
    {
        std::cout << "The weight is " << m_weight << m_unit << std::endl;
    }
};