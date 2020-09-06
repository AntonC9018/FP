#define uint unsigned int
#include <string>
#include <iostream>
#include "./container.cpp"
#include "./product.cpp"

typedef void (*OptionFunc)(Container<Product> &);

struct MenuOption
{
    OptionFunc optionFunc;
    std::string description;
};

class Menu
{
private:
    Container<Product> m_products;
    const static uint defaultProductCapacity = 100;

    // I would've used a dictionary here, but I'm not allowed to use
    // C++ data containers and don't feel like implementing a dictionary myself
    Container<MenuOption> m_options;
    const static uint defaultOptionCapacity = 10;

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
    Menu() : m_products(defaultProductCapacity),
             m_options(defaultOptionCapacity) {}

    // ideally, this would be AddOption(std::string key, const MenuOption &option)
    void AddOption(const MenuOption &option)
    {
        m_options.add(option);
    }

    void AddProduct(const Product &product)
    {
        m_products.add(product);
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