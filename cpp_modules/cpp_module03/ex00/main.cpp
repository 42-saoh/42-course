#include "ClapTrap.hpp"

int main()
{
    std::string clap("clap");
    std::string trap("trap");
    ClapTrap c1(clap);
    ClapTrap c2(trap);

    c1.showStatus();
    c2.showStatus();

    c1.attack("Trap");
    c2.takeDamege(1);
    c2.showStatus();
    c2.beRepaired(5);
    c2.showStatus();
}