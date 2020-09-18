#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include "./products/Product.h"

typedef void (*AddProductFunc)(ProductsVector &);

void PrintAll(ProductsVector &products);
void SetAll(ProductsVector &products);
void Sort(ProductsVector &products);
void PrintIfManufacturerMatches(ProductsVector &products);
void ChangeLast(ProductsVector &products);
void ModifyProduct(ProductsVector &products);
void AddSpecificProduct(ProductsVector &products);
void RemoveIfManufacturerMatches(ProductsVector &products);

template <typename T>
void AddProduct(ProductsVector &products)
{
    std::unique_ptr<T> product = std::make_unique<T>();
    product->PromptInputAll();
    products.push_back(std::move(product));
}