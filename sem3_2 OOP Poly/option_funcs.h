#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include "products/Product.h"
#include "MenuOption.h"

void PrintAll(ProductsVector &products)
{
    for (auto &product : products)
    {
        std::cout << std::endl;
        product->PrintAll();
    }
}

void SetAll(ProductsVector &products)
{
    for (auto &product : products)
        product->PromptInputAll();
}

void Sort(ProductsVector &products)
{
    std::sort(products.begin(), products.end(), [](std::unique_ptr<Product> &a, std::unique_ptr<Product> &b) {
        return b->GetName().compare(a->GetName());
    });
}

void PrintIfManufacturerMatches(ProductsVector &products)
{
    std::cout << std::endl;
    std::cout << "Specify the manufacturer whose products to show: ";
    std::string queriedManufacturer;
    std::cin >> queriedManufacturer;
    for (auto &product : products)
    {
        if (product->GetManufacturer() == queriedManufacturer)
        {
            product->PrintAll();
        }
    }
}

void ChangeLast(ProductsVector &products)
{
    if (products.size() == 0)
    {
        std::cout << "No product to modify" << std::endl;
    }
    products[products.size() - 1]->PromptInputAll();
}

void ModifyProduct(ProductsVector &products)
{
    if (products.size() == 0)
    {
        std::cout << "Nothing to remove" << std::endl;
        return;
    }

    std::cout << "Select the index at which to modify the product (max " << products.size() - 1 << "): ";
    int index;
    std::cin >> index;

    if (index >= products.size())
    {
        std::cout << "Specified index is out of range" << std::endl;
        return;
    }

    products[index]->PromptInputAll();
}

void AddSpecificProduct(ProductsVector &products)
{
    std::cout << "Select what class of products to instantiate: ";

    for (auto kvp : Product::Map)
    {
        std::cout << kvp.first << " ";
    }

    std::cout << std::endl;
    std::string selectedClassName;
    std::cin >> selectedClassName;

    try
    {
        Product::Map.at(selectedClassName)(products);
    }
    catch (const std::exception &e)
    {
        std::cout << "Such product type does not exist" << std::endl;
    }
}

void RemoveIfManufacturerMatches(ProductsVector &products)
{
    std::cout << std::endl;
    std::cout << "Specify the manufacturer whose products to remove: ";
    std::string queriedManufacturer;
    std::cin >> queriedManufacturer;
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i]->GetManufacturer() == queriedManufacturer)
        {
            products.erase(products.begin() + i);
        }
    }
}

template <typename T>
void AddProduct(ProductsVector &products)
{
    std::unique_ptr<T> product = std::make_unique<T>();
    product->PromptInputAll();
    products.push_back(std::move(product));
}