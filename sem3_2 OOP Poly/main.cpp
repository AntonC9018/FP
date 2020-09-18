// https://moodle.usm.md/mod/assign/view.php?id=71065
#include "./products/Product.h"
#include "./products/BookProduct.h"
#include "./products/ProductWithWeight.h"
#include "./products/TextProduct.h"
#include "./menu.h"
// #include "./option_funcs.h"

int main()
{
    // Product::Map.insert({"WithWeight", AddProduct<ProductWithWeight>});
    // Product::Map.insert({"Text", AddProduct<TextProduct>});
    // Product::Map.insert({"Book", AddProduct<BookProduct>});

    Menu menu = Menu();

    // MenuOption addOption{
    //     optionFunc : AddSpecificProduct,
    //     description : "ADD a new product of a specific type"
    // };
    // MenuOption printOption{
    //     optionFunc : PrintAll,
    //     description : "PRINT all product data"
    // };
    // MenuOption sortOption{
    //     optionFunc : Sort,
    //     description : "SORT products by name"
    // };
    // MenuOption manufacturerOption{
    //     optionFunc : PrintIfManufacturerMatches,
    //     description : "Input a manufacturer's name and PRINT products that have name match the specified name"
    // };
    // MenuOption modifyOption{
    //     optionFunc : ModifyProduct,
    //     description : "Input an index and MODIFY the product at that index"
    // };
    // MenuOption manufacturerRemoveOption{
    //     optionFunc : RemoveIfManufacturerMatches,
    //     description : "Input a manufacturer's name and REMOVE products that have name match the specified name"
    // };

    // menu.AddOption(addOption);
    // menu.AddOption(printOption);
    // menu.AddOption(sortOption);
    // menu.AddOption(manufacturerOption);
    // menu.AddOption(modifyOption);
    // menu.AddOption(manufacturerRemoveOption);

    menu.Start();

    return 0;
}
