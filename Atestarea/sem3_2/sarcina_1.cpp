#include <string>
#include <iostream>

class Tara
{
private:
    std::string m_denumirea;
    std::string m_capitala;

protected:
    int m_num_populatiei;
    int m_suprafata; // in km^2

public:
    Tara() = default;
    Tara(std::string denumirea, std::string capitala, int num_populatiei, int suprafata)
        : m_denumirea(denumirea), m_capitala(capitala), m_num_populatiei(num_populatiei), m_suprafata(suprafata) {}

    void input()
    {
        std::cout << "Denumirea: ";
        std::cin >> m_denumirea;

        std::cout << "Capitala: ";
        std::cin >> m_capitala;

        std::cout << "Populatia: ";
        std::cin >> m_num_populatiei;

        std::cout << "Suprafata: ";
        std::cin >> m_suprafata;
    }

    void print()
    {
        std::cout << "Denumirea: " << m_denumirea << std::endl;
        std::cout << "Capitala: " << m_capitala << std::endl;
        std::cout << "Populatia: " << m_num_populatiei << std::endl;
        std::cout << "Suprafata: " << m_suprafata << std::endl;
    }
};

class Republica : Tara
{
private:
    std::string m_presedintele;
    bool m_isDemocratic;

public:
    Republica() = default;
    Republica(std::string denumirea, std::string capitala, int num_populatiei, int suprafata,
              std::string presedintele, bool isDemocratic)
        : Tara(denumirea, capitala, num_populatiei, suprafata),
          m_presedintele(presedintele), m_isDemocratic(isDemocratic) {}

    void input()
    {
        Tara::input();
        std::cout << "Presedintele: ";
        std::cin >> m_presedintele;

        std::cout << "Este Democratica? (1 - da, 0 - nu): ";
        std::cin >> m_isDemocratic;
    }

    void print()
    {
        Tara::print();
        std::cout << "Presedintele: " << m_presedintele << std::endl;
        std::cout << (m_isDemocratic ? "Este democratica " : "Nu este democratica") << std::endl;
    }
};

class Dictatura : Tara
{
private:
    std::string m_dictatorul;
    std::string m_generalul;

public:
    Dictatura() = default;
    Dictatura(std::string denumirea, std::string capitala, int num_populatiei, int suprafata,
              std::string dictatorul, std::string generalul)
        : Tara(denumirea, capitala, num_populatiei, suprafata),
          m_dictatorul(dictatorul), m_generalul(generalul) {}

    void input()
    {
        Tara::input();
        std::cout << "Dictatorul: ";
        std::cin >> m_dictatorul;

        std::cout << "Generalul: ";
        std::cin >> m_generalul;
    }

    void print()
    {
        Tara::print();
        std::cout << "Dictatorul: " << m_dictatorul << std::endl;
        std::cout << "Generalul: " << m_generalul << std::endl;
    }
};

int main()
{
    Republica moldova("Moldova", "Chisinau", 1000000, 5000, "Maia Sandu", true);
    Dictatura corea_de_nord("Corea de Nord", "Pyongyang", 1000000, 6000, "Kim Jong-un", "Kim Jong-un");

    moldova.print();
    corea_de_nord.print();

    Republica test_no_args;
    test_no_args.input();
    test_no_args.print();

    Dictatura test_no_args_2;
    test_no_args_2.input();
    test_no_args_2.print();

    return 0;
}