#pragma once
#include <string>
#include "./products/Product.h"

typedef std::vector<std::unique_ptr<Product>> ProductsVector;
typedef void (*OptionFunc)(ProductsVector &);

struct MenuOption
{
    OptionFunc optionFunc;
    std::string description;
};