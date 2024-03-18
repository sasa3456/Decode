//------------------------------------------
//              Decode Main
//------------------------------------------


// Includes
#include "Decoder/Decoder.h"
#include "Menu/Menu.h"


// Main
int main(int argc, char argv[])
{
    setlocale(LC_ALL, "Ru-ru");

    const char* arr[4] = 
    {
        {"Двоичная кодировка"}, 
        {"Шестнадцатеричная кодировка"}, 
        {"Восьмеричная кодировка"}, 
        {"Выход"}
    };

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    Decode::Menu menu;
    std::string input;

    bool done = true;
    while (done) 
    {
        switch (menu.select_menu(90, 1, arr, 4, 2)) 
        {

        case 0:
            std::cout << "Введите текст <<";
            std::cin >> input;
            std::cout << Decode::Decoder::textToBinaryString(input) << std::endl;
            break;

        case 1: 
            std::cout << "Введите текст <<";
            std::cin >> input;
            std::cout << Decode::Decoder::textToHexadecimalString(input) << std::endl;
            break;

        case 2:
            std::cout << "Введите текст <<";
            std::cin >> input;
            std::cout << Decode::Decoder::textToOctalString(input) << std::endl;
            break;

        case 3:
            done = false;
            break;

        }
    }

    return 0;
}