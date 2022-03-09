#include "../inc/mainMenu.hpp"
#include <string>
#include <iostream>

MainMenu::MainMenu(){}

void MainMenu::printMainMenu()
    {
        std::cout<<"\n\n\n\n\n\n\n\nMenu Główne:\n"<<"Wybierz rodzaj paliwa:\n\n"
        <<"D - Disel\n"<<"B - Benzyna\n"<<"G - Gaz\n\n"<<"E - Wyjście z programu\n->";
    }