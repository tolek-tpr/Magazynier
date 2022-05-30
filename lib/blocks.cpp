 #include <iostream>

using namespace std;

typedef string GameMap[16];

const char EMPTY = ' ';
const char TARGET = '+';
const char CRATE = 'O';
const char LOCKED_CRATE = '0';
const char PLAYER = '$';
const char WALL = '#';

inline char getBlock(int x, int y, GameMap map) {
    return map[y][x];
}

inline bool isBlockEmpty(int x, int y, GameMap map) {
    return getBlock(x, y, map) == TARGET || getBlock(x, y, map) == EMPTY;
}

inline bool isBlockCrate(int x, int y, GameMap map) {
    return getBlock(x, y, map) == CRATE;
}

void pushCrate(int x1, int y1, int x2, int y2, GameMap& map) {
    map[y2][x2] = (getBlock(x2, y2, map) == TARGET) ? LOCKED_CRATE : CRATE;
    map[y1][x1] = EMPTY;
}

bool isComplete(GameMap map) {
    for (int y = 0; y < 16; y++) {
        for (int x = 0; x < map[y].length(); x++) {
            if (getBlock(x, y, map) == CRATE) return false;
        }
    }
    return true;
}