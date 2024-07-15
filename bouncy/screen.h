#ifndef SCREEN_H 
#define  SCREEN_H
#include "raylib.h"

typedef struct screenSize{
  int screenWidht;
  int screenHeight;
  char title[11];
} screenSize;

void GetScreen(screenSize *screenSize);

#endif 
