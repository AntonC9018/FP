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

    // I would've used a dictionary here, but I'm not allowed to use
    // C++ data std::vectors and don't feel like implementing a dictionary myself
    std::vector<MenuOption> m_options;

    const static int returnOption = -1;

    void PrintPromptText() const
    {
        std::cout << "Please select an option from the menu below." << std::endl;
        PrintDashes();
        int i = 0;
        for (auto iter = m_options.begin(); iter < m_options.end(); iter++)
        {
            std::cout << i << ": ";
            i++;
            std::cout << (*iter).description << std::endl;
        }
        std::cout << returnOption << ": Abort." << std::endl;
    }

    int AwaitOptionSelection() const
    {
        int input;
        std::cin >> input;
        return input;
    }

    void ExecuteOption(int optionIndex)
    {
        auto option = m_options[optionIndex];
        option.optionFunc(m_products);
    }

    void PrintDashes() const
    {
        std::cout << "-----------------------------"
                  << std::endl;
    }

    void AwaitEnter() const
    {
        std::cout << std::endl
                  << "Press enter to continue..." << std::endl;
        std::cin.get();
        while (std::cin.get() != '\n')
        {
        }
    }

public:
    Menu() = default;

    // ideally, this would be AddOption(std::string key, const MenuOption &option)
    void AddOption(const MenuOption &option)
    {
        m_options.push_back(option);
    }

    void AddProduct(std::unique_ptr<Product> product)
    {
        m_products.push_back(std::move(product));
    }

    void Start()
    {
        PrintDashes();
        while (true)
        {
            PrintPromptText();
            int input = AwaitOptionSelection();
            if (input == returnOption)
                return;
            PrintDashes();
            ExecuteOption(input);
            PrintDashes();
            AwaitEnter();
            PrintDashes();
        }
    }
};