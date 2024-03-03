#include <iostream>
#include <fstream>

class Address
{
private:
    std::string city, street;
    int building, appartment;
public:
    Address()
    {}

    Address(std::string city, std::string street, int building, int appartment)
    {
        this->city = city;
        this->street = street;
        this->building = building;
        this->appartment = appartment;
    }

    void print()
    {
        std::cout << this->city << std::endl;
        std::cout << this->street << std::endl;
        std::cout << this->building << std::endl;
        std::cout << this->appartment << std::endl;
    }

    std::string getCity()
    {
        return this->city;
    }
    std::string getStreet()
    {
        return this->street;
    }
    int getBuilding()
    {
        return this->building;
    }
    int getAppartment()
    {
        return this->appartment;
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");
    std::ifstream stream_for_count("in.txt");
    int address_size = 0;
    int size_of_elements = 0;
    int count = 0;
    Address* adresses = nullptr;
    
    std::string city = "";
    std::ifstream in("in.txt");
    
    if (in.is_open())
    {
        in >> address_size;
        size_of_elements = address_size * 4;
        std::string var1 = "";
        std::string var2 = "";
        int var3 = -1;
        int var4 = -1;
        std::cout << "in.txt" << std::endl;
        adresses = new Address[size_of_elements];
        while (!in.eof())
        {
            in >> var1;
            in >> var2;
            in >> var3;
            in >> var4;
            Address address(var1, var2, var3, var4);
            address.print();
            adresses[count++] = address;
        }
        in.close();
    }
    else
    {
        std::cout << "Ошибка открытия";
    }


    void sort(Address * addresses, int count);
















    std::cout << std::endl << "out.txt" << std::endl;
    for (int i = 0, j = address_size - 1; i < address_size; i++, j--)
    {
        adresses[j].print();
    }

    std::ofstream out("out.txt");
    for (int i = 0, j = address_size - 1; i < address_size; i++, j--)
    {
        out << adresses[j].getCity() << "\n";
        out << adresses[j].getStreet() << "\n";
        out << adresses[j].getBuilding() << "\n";
        out << adresses[j].getAppartment() << "\n";
    }
    out.close();
    delete[] adresses;
    return 0;
}
