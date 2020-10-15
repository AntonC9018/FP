#include <string>
#include <iostream>

class Medicament
{
private:
    std::string m_denumirea;
    std::string m_data_fabricarii;
    std::string m_cantitatea;
    std::string m_termenul_de_valabilitate;

public:
    Medicament()
        : m_denumirea("---"),
          m_data_fabricarii("---"),
          m_cantitatea("---"),
          m_termenul_de_valabilitate("---")
    {
    }

    Medicament(
        const std::string &denumirea,
        const std::string &data_fabricarii,
        const std::string &cantitatea,
        const std::string &termenul_de_valabilitate)
        : m_denumirea(denumirea),
          m_data_fabricarii(data_fabricarii),
          m_cantitatea(cantitatea),
          m_termenul_de_valabilitate(termenul_de_valabilitate)
    {
    }

    void input()
    {
        std::cout << "Denumirea: ";
        std::cin >> m_denumirea;

        std::cout << "Data Fabricarii: ";
        std::cin >> m_data_fabricarii;

        std::cout << "Cantitatea: ";
        std::cin >> m_cantitatea;

        std::cout << "Termenul de valabilitate: ";
        std::cin >> m_termenul_de_valabilitate;
    }

    void print()
    {
        std::cout << "Denumirea: " << m_denumirea << std::endl;
        std::cout << "Data Fabricarii: " << m_data_fabricarii << std::endl;
        std::cout << "Cantitatea: " << m_cantitatea << std::endl;
        std::cout << "Termenul de valvabilitate: " << m_termenul_de_valabilitate << std::endl;
    }

    bool test()
    {
        std::cout << "Which field to check?" << std::endl
                  << "1. Denumire" << std::endl
                  << "2. Data Fabricarii" << std::endl
                  << "3. Cantitatea" << std::endl
                  << "4. Termenul de valvabilitate" << std::endl;
        char input;
        std::cin >> input;

        std::cout << "What value should it have? - ";
        std::string value;
        std::cin >> value;

        switch (input)
        {
        case '1':
            return value.compare(m_denumirea) == 0;
        case '2':
            return value.compare(m_data_fabricarii) == 0;
        case '3':
            return value.compare(m_cantitatea) == 0;
        case '4':
            return value.compare(m_termenul_de_valabilitate) == 0;

        default:
            std::cout << "Invalid option" << std::endl;
            return false;
        }
    }
};

int main()
{
    Medicament x = Medicament();
    Medicament y = Medicament("Medicament Y", "anul 2000", "20 kg", "pana la anul 2090");

    x.input();
    y.input();

    x.print();
    y.print();

    bool result = x.test();
    std::cout << (result ? "Equal" : "Not equal");

    return 0;
}