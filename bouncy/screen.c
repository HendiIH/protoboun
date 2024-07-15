#include "raylib.h"
#include "screen.h"

void GetScreen(screenSize *screenSize) {
	InitWindow(screenSize->screenWidht, screenSize->screenHeight, screenSize->title);
}
