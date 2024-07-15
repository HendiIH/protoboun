#ifndef ENVITEM_H
#define ENVITEM_H
#include "raylib.h"

typedef struct ENVItem {
  Rectangle rect;
  int blocking;
  Color color;
}ENVItem;

void drawObstacle(ENVItem *envItem);

#endif // !ENVITEM_H
