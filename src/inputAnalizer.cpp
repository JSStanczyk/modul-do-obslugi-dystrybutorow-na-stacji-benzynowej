#include "../inc/inputAnalizer.hpp"
#include <iostream>

InputAnalizer::InputAnalizer()
    {
        userChoice='l';
    }

void InputAnalizer::getUserChoice()
    {
        for(;;)
            {
                std::cin>>userChoice;
                if(userChoice=='b'||'B'||'d'||'D'||'g'||'G'||'s'||'S'||'e'||'E'||'z'||'Z') break;
                else std::cout<<"Wciśnięto nie prawidłowy przycisk"<<std::endl;
            }
    }

char InputAnalizer::giveUserChioce()
    {
        return userChoice;
    }