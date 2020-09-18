#pragma once
#include <string>
#include "./ProductBaseParams.h"

struct BookParams : ProductBaseParams
{
    int weight;
    int numPages;
    std::string style;
    std::string unit;
    std::string author;
};