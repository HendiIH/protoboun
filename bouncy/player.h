#ifndef PLAYER_H
#define PLAYER_H
#include "envitem.h"
#include "raylib.h"

typedef struct Player {
	Vector2 position;
	float speed;
	bool canJump;
  Color color;
  float radius;
} Player;

void drawPlayer(Player *player);
void movePlayer(Player *player, float delta, ENVItem *envitem, int envitemlenght);

#endif
