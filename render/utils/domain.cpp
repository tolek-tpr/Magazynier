#include<iostream>

using namespace std;

typedef string GameMap[16];



string escapeMenu[8] {
    "###################",
    "# 1    CLOSE      #",
    "# 2  SETTINGS     #",
    "###################"
};

void swapBlock(int x1, int y1, int x2, int y2, GameMap& gameMap) {
    char tempBlock = gameMap[y2][x2];
    gameMap[y2][x2] = gameMap[y1][x1];
    gameMap[y1][x1] = tempBlock;
    cout << gameMap[y1][x1] << " to " << gameMap[y2][x2];
}