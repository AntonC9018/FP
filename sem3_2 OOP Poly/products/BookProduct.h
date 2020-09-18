#pragma once
#include <string>
#include "./Product.h"
#include "./ProductWithWeight.h"
#include "./TextProduct.h"
#include "./BookParams.h"

class BookProduct : public ProductWithWeight, public TextProduct
{
private:
    std::string m_author;

public:
    BookProduct();
    BookProduct(const BookParams &params);

    void PromptInputAll() override;
    void PrintAll() const override;
};