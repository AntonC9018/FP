#pragma once
#include <iostream>
#include "./Product.h"
#include "./ProductWithWeight.h"
#include "./TextProduct.h"

struct BookParams
{
    ProductBaseParams baseParams;
    int weight;
    int numPages;
    std::string style;
    std::string unit;
    std::string author;
};

class BookProduct : public ProductWithWeight, public TextProduct
{
private:
    std::string m_author;

public:
    BookProduct() = default;

    BookProduct(const BookParams &params)
        : Product(params.baseParams),
          ProductWithWeight(params.weight, params.unit),
          TextProduct(params.numPages, params.style),
          m_author(params.author) {}

    void PromptInputAll() override
    {
        Product::PromptInputAll();
        ProductWithWeight::PromptInputSpecific();
        TextProduct::PromptInputSpecific();
        std::cout << "Enter the author of the book: ";
        std::cin >> m_author;
    }

    void PrintAll() const override
    {
        Product::PrintAll();
        ProductWithWeight::PrintSpecific();
        TextProduct::PrintSpecific();
        std::cout << "The title of the book is " << m_author << std::endl;
    }
};