#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include"render/render.cpp"

using namespace std;

GameMap gameMap = {
    "####################           #    #   #######################",
    "#        #         #           #    #   #                     #",
    "#                  #############    #####                     #",
    "#                                                     #########",
    "##########                                            #       #",
    "#     #     O      #########    #########             #       #",
    "#                  #       #    #       #             #       #",
    "####################       #    #       ###############       #",
    "#                          #                                  #",
    "############################                                  #",
    "#                          #    #          +                  #",
    "#                          #    #                             #",
    "#                               #                             #",
    "#                               #                             #",
    "#                          #    #                             #",
    "############################    ###############################",
};

void clearScreen() {
    #ifdef _WIN32
    if (std::getenv("HOME"))   // git-bash & cygwin home var is called HOME
        std::system("clear");  // cmd's home var is called HOMEPATH
    else
        std::system("cls");
    #else
        // Assume POSIX
        std::system("clear");
    #endif
}

char getBlock(int x, int y, GameMap gameMap) {
    return gameMap[y][x];
}

bool isBlockEmpty(int x, int y, GameMap gameMap) {
    char block = getBlock(x, y, gameMap);
    return block == '+' || block == ' ';
}

bool isBlockCrate(int x, int y, GameMap gameMap) {
    return getBlock(x, y, gameMap) == 'O';
}

int main() {
    //GameMap gameMap;
    bool escapeMenuToggled = false;
    bool settingsMenuToggled;
    bool doExit = false;
    int pX = 1;
    int pY = 1;
    while (!doExit) {
        if (!escapeMenuToggled) {
            clearScreen();
            drawMap(pX, pY, gameMap);
        }
        else {
            clearScreen();
            drawEscapeMenu();
        }

        int key = _getch();
        switch (key) {
            case 97: 
                if (isBlockCrate(pX - 1, pY, gameMap) && isBlockEmpty(pX - 2, pY, gameMap)) { cout << "dupa"; swapBlock(pX - 1, pY, pX - 2, pY, gameMap); }
                if (isBlockEmpty(pX - 1, pY, gameMap)) pX--;
                break;
            case 100:
                if (isBlockCrate(pX + 1, pY, gameMap) && isBlockEmpty(pX + 2, pY, gameMap)) { cout << "dupa"; swapBlock(pX + 1, pY, pX + 2, pY, gameMap); }
                if (isBlockEmpty(pX + 1, pY, gameMap)) pX++;
                break;
            case 119: 
                if (isBlockCrate(pX, pY - 1, gameMap) && isBlockEmpty(pX, pY - 2, gameMap)) { cout << "dupa"; swapBlock(pX, pY - 1, pX, pY - 2, gameMap); }
                if (isBlockEmpty(pX, pY - 1, gameMap)) pY--;
                break;
            case 115: 
                if (isBlockCrate(pX, pY + 1, gameMap) && isBlockEmpty(pX, pY + 2, gameMap)) { cout << "dupa"; swapBlock(pX, pY + 1, pX, pY + 2, gameMap); }
                if (isBlockEmpty(pX, pY + 1, gameMap)) pY++;
                break;
            case 27: escapeMenuToggled = !escapeMenuToggled; break;
            case 49: if (escapeMenuToggled) doExit = true; break;
            case 50: if (escapeMenuToggled) { settingsMenuToggled = !settingsMenuToggled; cout << "settings"; } break;
        }
    }

    return 0;
}