#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

struct Character {
    std::string name;
    std::string role;
    int health;
    int attack;
    int defense;
};

void displayClassOptions() {
    std::cout << "Choose your class:\n";
    std::cout << "1. Warrior - High health and defense, moderate attack.\n";
    std::cout << "2. Mage - Low health, high attack and magic power.\n";
    std::cout << "3. Rogue - Moderate health, low defense, high speed and attack.\n";
    std::cout << "4. Assassin - Moderate health, very high attack, low defense but stealth abilities.\n";
}

Character createCharacter() {
    Character player;
    int choice;

    std::cout << "Enter your character's name: ";
    std::cin >> player.name;

    displayClassOptions();
    std::cout << "Enter the number corresponding to your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            player.role = "Warrior";
            player.health = 150;
            player.attack = 50;
            player.defense = 80;
            break;
        case 2:
            player.role = "Mage";
            player.health = 100;
            player.attack = 90;
            player.defense = 40;
            break;
        case 3:
            player.role = "Rogue";
            player.health = 120;
            player.attack = 70;
            player.defense = 60;
            break;
        case 4:
            player.role = "Assassin";
            player.health = 110;
            player.attack = 100;
            player.defense = 40;
            break;
        default:
            std::cout << "Invalid choice! Defaulting to Warrior.\n";
            player.role = "Warrior";
            player.health = 150;
            player.attack = 50;
            player.defense = 80;
    }

    std::cout << "\nCharacter Created!\n";
    std::cout << "Name: " << player.name << "\n";
    std::cout << "Class: " << player.role << "\n";
    std::cout << "Health: " << player.health << "\n";
    std::cout << "Attack: " << player.attack << "\n";
    std::cout << "Defense: " << player.defense << "\n";

    return player;
}

void combat(Character& player) {
    int enemyHealth = 50, enemyAttack, playerAction;
    std::srand(std::time(0));

    std::cout << "\nA wild monster appears!\n";

    while (player.health > 0 && enemyHealth > 0) {
        // Player's turn
        std::cout << "Choose an action: (1) Attack (2) Defend\n";
        std::cin >> playerAction;

        if (playerAction == 1) {
            int playerAttack = std::rand() % player.attack + 5; // Random damage based on player's attack stat
            enemyHealth -= playerAttack;
            std::cout << "You attacked and dealt " << playerAttack << " damage!\n";
        } else if (playerAction == 2) {
            std::cout << "You defended against the enemy's next attack!\n";
        } else {
            std::cout << "Invalid choice! You lost your turn.\n";
        }

        if (enemyHealth <= 0) break;

        // Enemy's turn
        enemyAttack = std::rand() % 15 + 5; // Random damage 5-20
        if (playerAction == 2) enemyAttack /= 2; // Reduced damage if defended
        player.health -= enemyAttack;
        std::cout << "The enemy attacked and dealt " << enemyAttack << " damage!\n";

        std::cout << "Your health: " << player.health << ", Enemy health: " << enemyHealth << "\n";
    }

    if (player.health > 0)
        std::cout << "\nYou defeated the monster!\n";
    else
        std::cout << "\nYou were defeated. Game Over.\n";
}

void explore(Character& player){
    std::srand(std::time(0));
    bool exploring = true;


        while (exploring && player.health > 0) {
        std::cout << "\nYou are exploring the wilderness...\n";
        int event = std::rand() % 3; // Random event: 0 - Nothing, 1 - Encounter Monster, 2 - Find Treasure
        if (event == 0) {
            std::cout << "It's quiet... nothing happens.\n";
        } else if (event == 1) {
            std::cout << "You encounter a monster!\n";
            combat(player);
        } else if (event == 2) {
            int healthBoost = std::rand() % 20 + 10; // Health boost between 10 and 30
            player.health += healthBoost;
            std::cout << "You found a treasure chest with a health potion! Your health increased by " << healthBoost << ".\n";
        }

        std::cout << "Do you want to continue exploring? (1) Yes (2) No\n";
        int choice;
        std::cin >> choice;
        if (choice == 2) exploring = false;
    }

    while (exploring && player.health > 0) {
        std::cout << "\nYou are exploring the wilderness...\n";
        int event = std::rand() % 3; // Random event: 0 - Nothing, 1 - Encounter Monster, 2 - Find Treasure
        if (event == 0) {
            std::cout << "It's quiet... nothing happens.\n";
        } else if (event == 1) {
            std::cout << "You encounter a monster!\n";
            combat(player);
        } else if (event == 2) {
            int healthBoost = std::rand() % 20 + 10; // Health boost between 10 and 30
            player.health += healthBoost;
            std::cout << "You found a treasure chest with a health potion! Your health increased by " << healthBoost << ".\n";
        }

        std::cout << "Do you want to continue exploring? (1) Yes (2) No\n";
        int choice;
        std::cin >> choice;
        if (choice == 2) exploring = false;
    }
}

int main() {
    Character player = createCharacter();

    std::cout << "\nWhat would you like to do? (1) Explore (2) Quit\n";
    int mainChoice;
    std::cout << "\nWhere would you like to explore? (1) Dungeons (2) Forests (3) Mines (4) Quit";
    int explorelocation;
    std::cin >> mainChoice;

    if (mainChoice == 1) {
        explore(player);
    } else {
        std::cout << "Goodbye!\n";
    }

    return 0;
}
