#pragma once
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include "./AbstractProduct.h"
#include "./ProductBaseParams.h"

class Product : public AbstractProduct
{

private:
    std::string m_manufactureDate;
    std::string m_location;

protected:
    std::string m_name;
    std::string m_manifacturer;

public:
    typedef std::vector<std::unique_ptr<Product>> ProductsVector;
    typedef void (*AddProductFunc)(ProductsVector &);
    static std::map<std::string, AddProductFunc> Map;

    Product();
    Product(const ProductBaseParams &params);

    virtual void PromptInputAll();
    virtual void PrintAll() const;
    const std::string &GetName() const;
    const std::string &GetManufacturer() const;
};

#include "h"
