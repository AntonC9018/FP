#include <string>
#include <iostream>

class Product
{
private:
    std::string m_name;
    std::string m_manufactureDate;
    std::string m_manifacturer;
    int m_weight; // in kg

public:
    Product() {}

    // Product(std::string name,
    //         std::string date_manufactured,
    //         std::string manifacturer,
    //         int weight)
    // {
    //     m_name = name;
    //     m_date_manufactured = date_manufactured;
    //     m_manifacturer = manifacturer;
    //     m_weight = weight;
    // }

    // Daca utilizam initializare directa prin Product("pahar", ...)
    // Doar o copie va fi creata (copy elision)
    // https://stackoverflow.com/a/31129783/9731532
    Product(const std::string &name,
            const std::string &manufactureDate,
            const std::string &manifacturer,
            int weight)
        : m_name(name),
          m_manufactureDate(manufactureDate),
          m_manifacturer(manifacturer),
          m_weight(weight) {}

    void InputName()
    {
        std::cin >> m_name;
    }

    void InputManifactureDate()
    {
        std::cin >> m_manufactureDate;
    }

    void InputManufacturer()
    {
        std::cin >> m_manifacturer;
    }

    void InputWeight()
    {
        std::cin >> m_weight;
    }

    void PromptInputAll()
    {
        std::cout << "Enter name: ";
        InputName();
        std::cout << "Enter manifacture date: ";
        InputManifactureDate();
        std::cout << "Enter manifacturer: ";
        InputManufacturer();
        std::cout << "Enter weight: ";
        InputWeight();
    }

    void PrintName() const
    {
        std::cout << "Name: " << m_name << std::endl;
    }

    void PrintManifactureDate() const
    {
        std::cout << "Manufacture date: " << m_manufactureDate << std::endl;
    }

    void PrintManufacturer() const
    {
        std::cout << "Manufacturer: " << m_manifacturer << std::endl;
    }

    void PrintWeight() const
    {
        std::cout << "Weight: " << m_weight << "kg" << std::endl;
    }

    void PrintAll() const
    {
        PrintName();
        PrintManifactureDate();
        PrintManufacturer();
        PrintWeight();
    }

    const std::string &GetName() const
    {
        return m_name;
    }

    int GetWeight() const
    {
        return m_weight;
    }

    const std::string &GetManufacturer() const
    {
        return m_manifacturer;
    }
};