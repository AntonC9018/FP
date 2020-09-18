#pragma once
#include <string>
#include "./products/Product.h"

typedef void (*OptionFunc)(ProductsVector &);

struct MenuOption
{
    OptionFunc optionFunc;
    std::string description;
};