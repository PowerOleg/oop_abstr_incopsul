#include <iostream>
#include <fstream>



int main(int argc, char** argv)
{

    int var = 0;
    int index = 0;
    int size_to_print = 0;
    int* arr = NULL;
    std::ifstream in("in.txt");
    if (in.is_open())
    {
        in >> index;
        size_to_print = index;
        arr = new int[index];
        index--;
        while (!(in >> var).eof())
        {
            arr[index--] = var;
        }
        arr[index--] = var;//если эту строчку не писать, то последний символ не запишется
        in.close();
    }
    else
    {
        std::cout << "Ошибка открытия";
    }
	return 0;
}