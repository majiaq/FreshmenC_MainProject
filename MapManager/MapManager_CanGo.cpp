#include "MapManager.h"
#include <cstdio>
#include <cstdlib>

bool is_CanGo(int player, int x, int y, int i, int y);

bool MapManager_CanGo(const int player, const unsigned int x,
                      const unsigned int y) {
  if (x >= 9 || y >= 9 || x == 0 || y == 0) {
    return false;
  }
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (MapManager_Map[x][y] == BLANK &&
          MapManager_Map[x + i][y + j] == !player) {
        return is_CanGo(player, x + i, y + j, i, j);
      }
      return false;
    }
  }
}

bool is_CanGo(int player, int x, int y, int i, int j) {
  int tmp = MapManager_Map[x + i][y + j];
  if (tmp == !player) {
    return is_CanGo(player, x + i, y + j, i, j);
  }
  if (tmp == player) {
    return true;
  }
  return false;
}