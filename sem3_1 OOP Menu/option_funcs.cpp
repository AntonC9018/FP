
void PrintAll(Container<Product> &products)
{
    for (auto iter = products.begin(); iter < products.end(); iter++)
    {
        std::cout << std::endl;
        (*iter).PrintAll();
    }
}

void SetAll(Container<Product> &products)
{
    for (auto iter = products.begin(); iter < products.end(); iter++)
        (*iter).PromptInputAll();
}

void Sort(Container<Product> &products)
{
    /*
  `const Container<Product> &` is what used to be here

  Seems weird to me why I can't modify the state of the object
  doesn't a const reference just mean that the memory it is pointing to
  cannot be reassigned? I couldn't find much enlightening info on this.

  What I mean is I can't do `products = otherProducts`, but
  I should be able to do `products[1] = someProduct`

  As a workaround, I had to remove the `const` from the parameter.

  Update: through experience, I now get it. the `const` really does
  apply to the state of the container, so calling any methods that
  are not declared const is illegal. I wonder what is the version
  of this where the variable is not reassignable, but its state is mutable
  */
    products.sort([](const Product &a, const Product &b) {
        return -a.GetName().compare(b.GetName());
    });
}

void PrintIfManufacturerMatches(Container<Product> &products)
{
    std::cout << "Specify the manufacturer whose products to show: ";
    std::string queriedManufacturer;
    std::cin >> queriedManufacturer;
    for (auto iter = products.begin(); iter < products.end(); iter++)
    {
        if ((*iter).GetManufacturer() == queriedManufacturer)
        {
            std::cout << std::endl;
            (*iter).PrintAll();
        }
    }
}

void PrintIfWeightMatches(Container<Product> &products)
{
    std::cout << "Specify the weight, products of which to show: ";
    int queriedWeight;
    std::cin >> queriedWeight;
    for (auto iter = products.begin(); iter < products.end(); iter++)
    {
        if ((*iter).GetWeight() == queriedWeight)
        {
            std::cout << std::endl;
            (*iter).PrintAll();
        }
    }
}

void ChangeLast(Container<Product> &products)
{
    if (products.count() == 0)
    {
        std::cout << "No product to modify" << std::endl;
    }
    products[products.count() - 1].PromptInputAll();
}

void AddProduct(Container<Product> &products)
{
    /*
    // this doesn't work and I do not understand why
    // perhaps ultimately a copy is received after all
    try
    {
        Product product = products.add(Product());
        product.PromptInputAll();
    }
    // limit of the array exceeded
    catch (const std::string &s)
    {
        std::cerr << s << '\n';
    }
    */

    /*
    if I do it the other way around:
    */
    Product product = Product();
    product.PromptInputAll();
    products.add(product);
    /*
    since the container has to store that product by value rather than by reference,
    it will be copied together with its strings. It it practically possible to do this,
    but unnecessary copying should be avoided in my view.
    */
}