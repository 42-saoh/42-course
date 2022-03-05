#include "DiamondTrap.hpp"

int main()
{
    std::string clap("saoh");
    std::string frag("ohsa");
    DiamondTrap d1(clap);
    DiamondTrap d2(frag);

    d1.showStatus();
    d2.showStatus();

    d1.attack("ohsa");
    d2.takeDamege(30);
    d2.showStatus();
    d2.beRepaired(5);
    d2.showStatus();
    d2.attack("saoh");
    d1.takeDamege(30);
    d1.showStatus();
    d1.guardGate();
    d2.highFivesGuys();
}
