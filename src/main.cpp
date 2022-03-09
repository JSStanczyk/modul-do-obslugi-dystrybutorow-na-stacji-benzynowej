/*#include "../inc/billGenerator.hpp"
#include "../inc/supply.hpp"
#include "../inc/petrol.hpp"
#include "../inc/mainMenu.hpp"
#include "../inc/inputAnalizer.hpp"
#include "../inc/gas.hpp"
#include "../inc/fuel.hpp"
#include "../inc/distributor.hpp"
#include "../inc/customer.hpp"
#include "../inc/disel.hpp"*/
#include "../inc/mainSequence.hpp"
#include <memory>

int main(void)
{
    std::shared_ptr<MainSequence> mainSequence(new MainSequence);
    mainSequence->_do_();
    return 0;
}