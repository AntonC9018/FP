#pragma once
#include <iostream>
#include <string>
#include "./Product.h"

class TextProduct : public virtual Product
{
private:
    int m_numPages;
    std::string m_style;

protected:
    TextProduct(int numPages, const std::string &style)
        : m_numPages(numPages),
          m_style(style) {}

public:
    TextProduct() = default;

    TextProduct(const ProductBaseParams &params,
                int numPages,
                const std::string &style)
        : Product(params),
          m_numPages(numPages),
          m_style(style) {}

    void PromptInputAll() override
    {
        Product::PromptInputAll();
        PromptInputSpecific();
    }

    void PromptInputSpecific()
    {
        std::cout << "Enter the number of pages: ";
        std::cin >> m_numPages;
        std::cout << "Enter the style of writing: ";
        std::cin >> m_style;
    }

    void PrintAll() const override
    {
        Product::PrintAll();
        PrintSpecific();
    }

    void PrintSpecific() const
    {
        std::cout << "The number of pages is " << m_numPages << std::endl;
        std::cout << "Was written in " << m_style << " style" << std::endl;
    }
};