#include "Character.hpp"

// *****************************************
// Character definitions
// *****************************************
void Character :: displayInfo() const {
    std::cout << "Name: " << name << ", Health: " << health << std::endl;
    weapon.displayInfo();
}

void Character :: equipWeapon(Weapon& w) {
    weapon = w;
}

void Character :: attack(Character& op) const {
    std::cout << name << " attacks with ";
    weapon.displayInfo();
    std::cout << "Damage: " << weapon.getDamage() << std::endl;
    op.getHit(weapon.getDamage());
}

void Character :: specialAttack(Character& op) const {
    std::cout << name << " attacks with ";
    weapon.displayInfo();
    std::cout << "Damage: " << weapon.getDamage() << std::endl;
    op.getHit(weapon.specialAttack());
}

void Character :: getHit(int damage) {
    health -= damage;
    std::cout << name << " takes " << damage << " damage. Remaining health: " << health << std::endl;
}

// *****************************************
// Warrior definitions
// *****************************************
void Warrior :: attack(Character& op) const {
    int damage = weapon.getDamage() + strength;
    std::cout << "Warrior " << name << " swings his sword! Damage: " << damage << std::endl;
    op.getHit(damage);
}

void Warrior :: specialAttack(Character& op) const {
    int damage = weapon.specialAttack() + strength;
    std::cout << "Warrior " << name << " swings his sword with a special attack! Damage: " << damage << std::endl;
    op.getHit(damage);
}

void Warrior :: getHit(int damage) {
    if (strength > damage) {
        std::cout << "Warrior " << name << " blocks the attack!" << std::endl;
        return;
    }
    health -= damage;
    std::cout << "Warrior " << name << " takes " << damage << " damage. Remaining health: " << health << std::endl;
}

// *****************************************
// Wizard definitions - Fill these defintions for Wizard Derived Class. Take Refrence from Warrior Class
// *****************************************
void Wizard :: attack(Character& op) const {
    int damage = weapon.getDamage() + magicPower;
    std::cout << "Wizard " << name << " casts a spell! Damage: " << damage << std::endl;
    op.getHit(damage);
}

//Fill this out
void Wizard :: specialAttack(Character& op) const {
    int damage = weapon.specialAttack() + magicPower;
    std::cout << "Wizard " << name << " casts a powerful spell! Damage: " << damage << std::endl;
    op.getHit(damage);
}

//Fill this out
void Wizard :: getHit(int damage) {
    if (magicPower > damage) {
        std::cout << "Wizard " << name << " is immune to the attack!" << std::endl;
        return;
    }
    health -= damage;
    std::cout << "Wizard " << name << " takes " << damage << " damage. Remaining health: " << health << std::endl;
}

//Fill this out
void Wizard :: healingSpell() {
    health += int(1.25 * magicPower);
    std::cout << "Wizard " << name << " heals for " << int(1.25 * magicPower) << " health. Remaining health: " << health << std::endl;
}
