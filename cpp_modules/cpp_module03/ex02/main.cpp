#include "FragTrap.hpp"

int main()
{
    std::string clap("clap");
    std::string frag("frag");
    ClapTrap c1(clap);
    FragTrap f1(frag);

    c1.showStatus();
    f1.showStatus();

    c1.attack("scav");
    f1.takeDamege(20);
    f1.showStatus();
    f1.beRepaired(5);
    f1.showStatus();
    f1.attack("crap");
    c1.takeDamege(30);
    c1.showStatus();
    f1.highFivesGuys();
}