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
        std::cout << this->city << ", ";
        std::cout << this->street << ", ";
        std::cout << this->building << ", ";
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

void sort(Address* addresses, int count)
{
    for (int i = 0; i < count; i++)
    {
        addresses[i].getCity();
        addresses[i].getStreet();
        addresses[i].getBuilding();
        addresses[i].getAppartment();
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");
    std::ifstream stream_for_count("in.txt");
    int address_size = 0;
    int size_of_elements = 0;
    int count = 0;
    Address* addresses = nullptr;
    
    std::string city = "";
    std::ifstream in("in.txt");
    
    if (in.is_open())
    {
        in >> address_size;
        std::cout << "in.txt" << std::endl;
        std::cout << address_size << std::endl;
        size_of_elements = address_size * 4;
        std::string var1 = "";
        std::string var2 = "";
        int var3 = -1;
        int var4 = -1;
        addresses = new Address[size_of_elements];
        while (!in.eof())
        {
            in >> var1;
            in >> var2;
            in >> var3;
            in >> var4;
            Address address(var1, var2, var3, var4);
            address.print();
            addresses[count++] = address;
        }
        in.close();
    }
    else
    {
        std::cout << "Ошибка открытия";
    }
    sort(addresses, count);

    std::cout << std::endl << "out.txt" << std::endl << count << std::endl;
    for (int i = 0, j = address_size - 1; i < address_size; i++, j--)
    {
        addresses[j].print();
    }

    std::ofstream out("out.txt");
    out << count << "\n";
    for (int i = 0, j = address_size - 1; i < address_size; i++, j--)
    {
        out << addresses[j].getCity() << ", ";
        out << addresses[j].getStreet() << ", ";
        out << addresses[j].getBuilding() << ", ";
        out << addresses[j].getAppartment() << "\n";
    }
    out.close();
    delete[] addresses;
    return 0;
}
