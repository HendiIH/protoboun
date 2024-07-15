#ifndef CAMERA_H
#define CAMERA_H
#include "raylib.h"
#include "envitem.h"
#include "player.h"


void UpdateCameraCenterInsideMap(Camera2D *camera, Player *player, ENVItem *envItems, int envItemsLength, float delta, int width, int height);

#endif 
