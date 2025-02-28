#include <string>

#include "Character.hpp"
#include "Weapons.hpp"
#include "Character.cpp"


int main() {
    Sword warriorSword("Legendary Sword", 25);
    Staff wizardStaff("Enchanted Staff", 30);

    Warrior warrior("Aragorn", 100, warriorSword, 20);
    Wizard wizard("Gandalf", 80, wizardStaff, 30);

    // Display information, equip weapons, and perform attacks
    warrior.displayInfo();
    warrior.attack(wizard);

    std::cout << std::endl;

    wizard.displayInfo();
    wizard.specialAttack(warrior);
    wizard.healingSpell();

    std::cout << std::endl;
    
    // Create an object of a new weapon and change the warrior object using equipweapon. Change weapons and attack again
    Sword superSword("Super Sword", 30);
    warrior.equipWeapon(superSword);

    std::cout << std::endl;
    warrior.displayInfo();
    warrior.attack(wizard);


    return 0;
}