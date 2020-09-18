#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "./products/Product.h"
#include "./MenuOption.h"

class Menu
{
private:
    ProductsVector m_products;
    std::vector<MenuOption> m_options;
    const static int returnOption;

    void PrintPromptText() const;
    int AwaitOptionSelection() const;
    void ExecuteOption(int optionIndex);
    void PrintDashes() const;
    void AwaitEnter() const;

public:
    Menu();

    void AddOption(const MenuOption &option);
    void AddProduct(std::unique_ptr<Product> product);

    void Start();
};