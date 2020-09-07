// https://moodle.usm.md/mod/assign/view.php?id=71065
/*
    Tested with g++ main.cpp.

    # Notes on code style.

    I've been programming in c# recently, which is where the convention of calling 
    methods with capital letters is established. The reason why the `Container` class
    has lower-case methods is because I figured that it is sort of like a library
    class and they usually have snake_case c-style nomenclature.
*/
#include <string>
#include <iostream>
#include "./menu.cpp"
#include "./option_funcs.cpp"

void PrintAll(Container<Product> &products);
void SetAll(Container<Product> &products);
void Sort(Container<Product> &products);
void PrintIfManufacturerMatches(Container<Product> &products);
void PrintIfWeightMatches(Container<Product> &products);
void ChangeLast(Container<Product> &products);
void AddProduct(Container<Product> &products);

int main()
{
    Menu menu = Menu();

    MenuOption addOption{
        optionFunc : AddProduct,
        description : "Add a new product"
    };
    MenuOption printOption{
        optionFunc : PrintAll,
        description : "Print all product data"
    };
    MenuOption sortOption{
        optionFunc : Sort,
        description : "Sort products by name"
    };
    MenuOption manufacturerOption{
        optionFunc : PrintIfManufacturerMatches,
        description : "Input a manufacturer's name and print products that have name match the specified name"
    };
    MenuOption weightOption{
        optionFunc : PrintIfWeightMatches,
        description : "Input a weight in kg and add a new product before the first product that has that weight"
    };
    MenuOption changeLastOption{
        optionFunc : ChangeLast,
        description : "Respecify the last product's data"
    };

    menu.AddOption(addOption);
    menu.AddOption(printOption);
    menu.AddOption(sortOption);
    menu.AddOption(manufacturerOption);
    menu.AddOption(weightOption);
    menu.AddOption(changeLastOption);

    menu.Start();

    return 1;
}
