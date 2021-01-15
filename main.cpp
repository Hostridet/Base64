#include <iostream>
#include "base64.h"
#include <string>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int i = 1;
    std::cout << "Введите строку" << endl;
    string input;
    std::getline(std::cin,input);
    std::cout << "1 - кодировать, иначе декодировать" << std::endl;
    std::cin >> i;

    if (i == 1)
        std::cout << "Coded: " << Encode(input) << std::endl;
    else
        std::cout << "Decoded: " <<Decode(input) << std::endl;
    return 0;
}