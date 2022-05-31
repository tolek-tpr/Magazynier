#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "lib/blocks.cpp"
#include "lib/render.cpp"

using namespace std;

#ifdef _WIN32 // WIN32
#include <conio.h>
#define GETCH _getch
#else // POSIX
#include "headers/conio.h"
#define GETCH getch
#endif

const int MAX_LEVEL = 2;

GameMap levels[MAX_LEVEL] = {
    {
        "###########",
        "#   O    +#",
        "###########",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
    },
    {
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
    },
};

void clearScreen()
{
#ifdef _WIN32
    if (getenv("HOME"))
        system("clear");
    else
        system("cls");
#else
    // POSIX
    system("clear");
#endif
}

int main()
{
    GameMap *gameMap;
    bool escapeMenuToggled = false;
    bool settingsMenuToggled = false;
    bool mainMenuToggled = true;
    bool doExit = false;
    int pX = 1;
    int pY = 1;
    int level = 0;

    gameMap = &levels[level];

    while (!doExit)
    {
        if (!escapeMenuToggled && !mainMenuToggled)
        {
            clearScreen();
            drawMap(pX, pY, *gameMap);
        }
        else
        {
            if (escapeMenuToggled) {
                clearScreen();
                drawEscapeMenu();
            } else if (mainMenuToggled) {
                clearScreen();
                drawMainMenu();
            }
        }

        int key = GETCH();

        switch (key)
        {
        case 97:
            if (isBlockCrate(pX - 1, pY, *gameMap) && isBlockEmpty(pX - 2, pY, *gameMap))
            {
                pushCrate(pX - 1, pY, pX - 2, pY, *gameMap);
            }
            if (isBlockEmpty(pX - 1, pY, *gameMap))
                pX--;
            break;
        case 100:
            if (isBlockCrate(pX + 1, pY, *gameMap) && isBlockEmpty(pX + 2, pY, *gameMap))
            {
                pushCrate(pX + 1, pY, pX + 2, pY, *gameMap);
            }
            if (isBlockEmpty(pX + 1, pY, *gameMap))
                pX++;
            break;
        case 119:
            if (isBlockCrate(pX, pY - 1, *gameMap) && isBlockEmpty(pX, pY - 2, *gameMap))
            {
                pushCrate(pX, pY - 1, pX, pY - 2, *gameMap);
            }
            if (isBlockEmpty(pX, pY - 1, *gameMap))
                pY--;
            break;
        case 115:
            if (isBlockCrate(pX, pY + 1, *gameMap) && isBlockEmpty(pX, pY + 2, *gameMap))
            {
                pushCrate(pX, pY + 1, pX, pY + 2, *gameMap);
            }
            if (isBlockEmpty(pX, pY + 1, *gameMap))
                pY++;
            break;
        case 27:
            escapeMenuToggled = !escapeMenuToggled;
            break;
        case 49:
            if (escapeMenuToggled)
                doExit = true;
            if (mainMenuToggled)
                mainMenuToggled = false;
            break;
        case 50:
            if (escapeMenuToggled)
            {
                settingsMenuToggled = !settingsMenuToggled;
                cout << "settings";
            }
            
            break;
        }
        if (isComplete(*gameMap))
        {
            clearScreen();
            drawMap(pX, pY, *gameMap);
            if (level == MAX_LEVEL - 1)
            {
                cout << "Congratulations, you won!" << endl;
                doExit = 1;
            }
            else
            {
                gameMap = &levels[++level];
            }
        }
    }

    return 0;
}