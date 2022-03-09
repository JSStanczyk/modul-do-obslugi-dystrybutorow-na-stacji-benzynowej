#include "../inc/supplyMenu.hpp"
#include <iostream>

SupplyMenu::SupplyMenu(){}

void SupplyMenu::printSupplyMenu()
    {
        std::cout<<"\n\nDostawę, którego rodzaju paliwa chesz wykonać:\n"
                 <<"D - Disel\n"<<"B - Benzyna\n"<<"G - Gaz\n\n"
                 <<"E - Zrezygnuj\n\n->";
    }