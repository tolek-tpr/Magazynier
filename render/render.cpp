#include<iostream>
#include<stdio.h>
#include"utils/domain.cpp"

using namespace std;

void drawEscapeMenu() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < escapeMenu[y].length(); x++) {
            cout << escapeMenu[y][x];
        }
        cout << endl;
    }
}

void drawMap(int posX, int posY, GameMap gameMap) {
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < gameMap[y].length(); x++) {
            if (x == posX && y == posY) {
                cout << "$";
            }else {
                cout << gameMap[y][x];
            }
        }
        cout << endl;
    }
}