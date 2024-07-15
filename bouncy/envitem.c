#include "raylib.h"
#include "envitem.h"

void drawObstacle(ENVItem *envItem){
  DrawRectangleRec(envItem->rect, envItem->color);
}
