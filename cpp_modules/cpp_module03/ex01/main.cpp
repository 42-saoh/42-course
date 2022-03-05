#include "ScavTrap.hpp"

int main()
{
    std::string clap("clap");
    std::string scav("scav");
    ScavTrap c1(clap);
    ScavTrap s2(scav);

    c1.showStatus();
    s2.showStatus();

    c1.attack("scav");
    s2.takeDamege(20);
    s2.showStatus();
    s2.beRepaired(5);
    s2.showStatus();
    s2.attack("crap");
    c1.takeDamege(20);
    c1.showStatus();
    s2.guardGate();
}