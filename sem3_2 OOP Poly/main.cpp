// https://moodle.usm.md/mod/assign/view.php?id=71065
#include "products/Product.h"
#include "products/BookProduct.h"
#include "products/ProductWithWeight.h"
#include "products/TextProduct.h"
#include "Menu.h"
#include "option_funcs.h"

int main()
{
    Product::Map.insert({"WithWeight", AddProduct<ProductWithWeight>});
    Product::Map.insert({"Text", AddProduct<TextProduct>});
    Product::Map.insert({"Book", AddProduct<BookProduct>});

    Menu menu = Menu();

    auto p2 = std::make_unique<ProductWithWeight>(
        ProductBaseParams{
            name : "2",
            manufactureDate : "2",
            manifacturer : "2",
            location : "2",
        },
        2, "kg");
    menu.AddProduct(std::move(p2));

    auto p3 = std::make_unique<TextProduct>(
        ProductBaseParams{
            name : "3",
            manufactureDate : "3",
            manifacturer : "3",
            location : "3",
        },
        3, "3");
    menu.AddProduct(std::move(p3));

    auto p1 = std::make_unique<BookProduct>(
        BookParams{
            baseParams : {name : "1",
                          manufactureDate : "1",
                          manifacturer : "1",
                          location : "1"},
            weight : 1,
            numPages : 1,
            style : "1",
            unit : "kg",
            author : "1"
        });
    menu.AddProduct(std::move(p1));

    MenuOption addOption{
        optionFunc : AddSpecificProduct,
        description : "ADD a new product of a specific type"
    };
    MenuOption printOption{
        optionFunc : PrintAll,
        description : "PRINT all product data"
    };
    MenuOption sortOption{
        optionFunc : Sort,
        description : "SORT products by name"
    };
    MenuOption manufacturerOption{
        optionFunc : PrintIfManufacturerMatches,
        description : "Input a manufacturer's name and PRINT products that have name match the specified name"
    };
    MenuOption modifyOption{
        optionFunc : ModifyProduct,
        description : "Input an index and MODIFY the product at that index"
    };
    MenuOption manufacturerRemoveOption{
        optionFunc : RemoveIfManufacturerMatches,
        description : "Input a manufacturer's name and REMOVE products that have name match the specified name"
    };

    menu.AddOption(addOption);
    menu.AddOption(printOption);
    menu.AddOption(sortOption);
    menu.AddOption(manufacturerOption);
    menu.AddOption(modifyOption);
    menu.AddOption(manufacturerRemoveOption);

    menu.Start();

    return 0;
}
