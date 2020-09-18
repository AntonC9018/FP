#pragma once
#include <string>
#include "./Product.h"
#include "./ProductBaseParams.h"

class TextProduct : public virtual Product
{
private:
    int m_numPages;
    std::string m_style;

protected:
    TextProduct(int numPages, const std::string &style);

public:
    TextProduct();
    TextProduct(const ProductBaseParams &params,
                int numPages,
                const std::string &style);

    void PromptInputAll() override;
    void PromptInputSpecific();
    void PrintAll() const override;
    void PrintSpecific() const;
};