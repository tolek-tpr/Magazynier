#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include "lib/blocks.cpp"
#include "lib/render.cpp"

using namespace std;

GameMap gameMap = {
    "####################                                           ",
    "#                  #          #################                ",
    "#                  #          #               #                ",
    "#                  ############ ############# #         #####  ",
    "####### ###                     #           # #         #+++#  ",
    "#    O    #O       #########    #########   # #         #   #  ",
    "#    #             #       #    #       #   # #         #   #  ",
    "####################       #    #O      ##### ###########   #  ",
    "                           #                                #  ",
    "                           ###########  ################## ##  ",
    "                                     #  #                # #   ",
    "                                     #  ################## #   ",
    "                                     #                     #   ",
    "                                     #######################   ",
    "                                                               ",
    "                                                               ",
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

int main() {
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
                if (isBlockCrate(pX - 1, pY, gameMap) && isBlockEmpty(pX - 2, pY, gameMap)) { pushCrate(pX - 1, pY, pX - 2, pY, gameMap); }
                if (isBlockEmpty(pX - 1, pY, gameMap)) pX--;
                break;
            case 100:
                if (isBlockCrate(pX + 1, pY, gameMap) && isBlockEmpty(pX + 2, pY, gameMap)) { pushCrate(pX + 1, pY, pX + 2, pY, gameMap); }
                if (isBlockEmpty(pX + 1, pY, gameMap)) pX++;
                break;
            case 119: 
                if (isBlockCrate(pX, pY - 1, gameMap) && isBlockEmpty(pX, pY - 2, gameMap)) { pushCrate(pX, pY - 1, pX, pY - 2, gameMap); }
                if (isBlockEmpty(pX, pY - 1, gameMap)) pY--;
                break;
            case 115: 
                if (isBlockCrate(pX, pY + 1, gameMap) && isBlockEmpty(pX, pY + 2, gameMap)) { pushCrate(pX, pY + 1, pX, pY + 2, gameMap); }
                if (isBlockEmpty(pX, pY + 1, gameMap)) pY++;
                break;
            case 27: escapeMenuToggled = !escapeMenuToggled; break;
            case 49: if (escapeMenuToggled) doExit = true; break;
            case 50: if (escapeMenuToggled) { settingsMenuToggled = !settingsMenuToggled; cout << "settings"; } break;
        }
        if (isComplete(gameMap)) {
            clearScreen();
            drawMap(pX, pY, gameMap);
            cout << "Congratulations, you won!" << endl;
            doExit = 1;
        }
    }

    return 0;
}