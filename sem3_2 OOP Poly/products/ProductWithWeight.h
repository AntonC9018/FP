#pragma once
#include <string>
#include "./Product.h"
#include "./ProductBaseParams.h"

class ProductWithWeight : public virtual Product
{
private:
    int m_weight;
    std::string m_unit;

protected:
    ProductWithWeight(int weight, const std::string &unit);

public:
    ProductWithWeight();

    ProductWithWeight(const ProductBaseParams &params,
                      int weight,
                      const std::string &unit);
    void PromptInputAll() override;
    void PromptInputSpecific();
    void PrintAll() const override;
    void PrintSpecific() const;
};