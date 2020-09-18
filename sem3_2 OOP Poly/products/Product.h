#pragma once
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include "./AbstractProduct.h"

struct ProductBaseParams
{
    std::string name;
    std::string manufactureDate;
    std::string manifacturer;
    std::string location;
};

class Product : public AbstractProduct
{
private:
    std::string m_manufactureDate;
    std::string m_location;

protected:
    std::string m_name;
    std::string m_manifacturer;

public:
    typedef void (*AddProductFunc)(std::vector<std::unique_ptr<Product>> &);
    static std::map<std::string, AddProductFunc> Map;

    Product() = default;

    Product(const ProductBaseParams &params)
        : m_name(params.name),
          m_manufactureDate(params.manufactureDate),
          m_manifacturer(params.manifacturer),
          m_location(params.location) {}

    virtual void PromptInputAll()
    {
        std::cout << "Enter name: ";
        std::cin >> m_name;
        std::cout << "Enter manifacture date: ";
        std::cin >> m_manufactureDate;
        std::cout << "Enter manifacturer: ";
        std::cin >> m_manifacturer;
        std::cout << "Enter location: ";
        std::cin >> m_location;
    }

    virtual void PrintAll() const
    {
        std::cout << "Name: " << m_name << std::endl;
        std::cout << "Manufacture date: " << m_manufactureDate << std::endl;
        std::cout << "Manufacturer: " << m_manifacturer << std::endl;
        std::cout << "Location: " << m_location << std::endl;
    }

    const std::string &GetName() const
    {
        return m_name;
    }

    const std::string &GetManufacturer() const
    {
        return m_manifacturer;
    }
};

std::map<std::string, Product::AddProductFunc> Product::Map = {};
