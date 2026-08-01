#include <iostream>
#include <cmath>
#include <string>

int getValidNum(std::string prompt);
int calculateBlocks(int x1, int y1, int x2, int y2);

int main(){
    int choice;
    int x1;
    int x2;
    int y1;
    int y2;
    int blocks;
    std::cout << "=========================" << '\n';
    std::cout << "Minecraft tools" << '\n';
    std::cout << "1) Block Calculator" << std::endl
              << "2) Railway Calculator" << std::endl;
    while(true){
        std::cout << "=========================" << '\n';
        choice = getValidNum("Enter your choice >>> ");
        if(choice==1){
            std::cout << "=========================" << '\n';
            std::cout << "Selected - BLOCK CALCULATOR" << '\n';
            int distance = calculateBlocks(x1,y1,x2,y2);
            std::cout << "Total Blocks between " << x1 << "," << y1 << "," << " and " << x2 << "," << y2 << " are: ";
            std::cout << distance << '\n';
        }
        else if(choice==2){
            std::cout << "=========================" << '\n';
            std::cout << "Selected - RAILWAY CALCULATOR" << '\n';
            std::cout << "=========================" << '\n';
            blocks = getValidNum("Enter total number of blocks >>> ");
            int poweredRails = blocks/8;
            int normalRails = blocks - (poweredRails);
            std::cout << "Total rails : " << normalRails/64 << " stack and " << normalRails%64 << " blocks" <<'\n';
            std::cout << "Total powered rails " << poweredRails/64 << " stack and " << poweredRails%64 << " blocks" << '\n';
        }
        else{
            std::cout << "Invalid choice." << '\n';
        }
    }

    return 0;
}

int getValidNum(std::string prompt){
    while(true){
        int choice;
        std::cout << prompt;
        std::cin >> choice;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000000,'\n');
            std::cout << "Input should be a number!" << '\n';
            continue;
        }
        else{
            return choice;
        }
    }
}

int calculateBlocks(int x1, int y1, int x2, int y2){
    std::cout << "=========================" << '\n';
    x1 = getValidNum("Enter X co-ordinate of the initial place >>> ");
    y1 = getValidNum("Enter Y co-ordinate of the initial place >>> ");
    x2 = getValidNum("Enter X co-ordinate of the final place >>> ");
    y2 = getValidNum("Enter Y co-ordinate of the final place >>> ");
    int distance = round(sqrt(pow(x2-x1,2) + pow(y2-y1,2)));
    return distance;
}