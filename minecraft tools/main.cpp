#include <iostream>
#include <cmath>
#include <string>

int getValidNumber(std::string prompt);
int calculateDistance();

int main() {
    int choice;

    std::cout << "=========================" << '\n';
    std::cout << "   MINECRAFT TOOLS" << '\n';
    std::cout << "=========================" << '\n';
    std::cout << "1) Block Calculator" << '\n'
              << "2) Railway Calculator" << '\n';
    std::cout << "=========================" << '\n';

    while (true) {
        choice = getValidNumber("Enter your choice >>> ");

        if (choice == 1) {
            std::cout << "=========================" << '\n';
            std::cout << "Selected - BLOCK CALCULATOR" << '\n';
            std::cout << "=========================" << '\n';

            int distance = calculateDistance();
            std::cout << "Distance: " << distance << " blocks" << '\n';
        }
        else if (choice == 2) {
            std::cout << "=========================" << '\n';
            std::cout << "Selected - RAILWAY CALCULATOR" << '\n';
            std::cout << "=========================" << '\n';

            int totalBlocks = getValidNumber("Enter total number of blocks >>> ");

            int poweredRailCount = totalBlocks / 8;
            int normalRailCount  = totalBlocks - poweredRailCount;

            std::cout << "Total rails:         " << normalRailCount / 64 << " stacks and " << normalRailCount % 64 << " blocks" << '\n';
            std::cout << "Total powered rails: " << poweredRailCount / 64 << " stacks and " << poweredRailCount % 64 << " blocks" << '\n';
        }
        else {
            std::cout << "Invalid choice." << '\n';
        }

        std::cout << "=========================" << '\n';
    }

    return 0;
}

int getValidNumber(std::string prompt) {
    while (true) {
        int number;
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000000, '\n');
            std::cout << "Input should be a number!" << '\n';
            continue;
        }

        return number;
    }
}

int calculateDistance() {
    int startX;
    int startY;
    int endX;
    int endY;

    startX = getValidNumber("Enter X co-ordinate of the starting point >>> ");
    startY = getValidNumber("Enter Y co-ordinate of the starting point >>> ");
    endX   = getValidNumber("Enter X co-ordinate of the ending point   >>> ");
    endY   = getValidNumber("Enter Y co-ordinate of the ending point   >>> ");

    int distance = round(sqrt(pow(endX - startX, 2) + pow(endY - startY, 2)));

    std::cout << "Total blocks between (" << startX << ", " << startY << ") and ("
              << endX << ", " << endY << ") are: ";
    return distance;
}
