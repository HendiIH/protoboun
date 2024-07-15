#ifndef ENEMY_H
#define ENEMY_H
#include "envitem.h"
#include "raylib.h"

typedef struct Enemy{
	Vector2 position;
	float speed;
	bool canJump;
  Color color;
  Vector2 side;
} Enemy;

void drawEnemy(Enemy *enemy);
void moveEnemy(Enemy *enemy, float delta, ENVItem *envitem, int envitemlenght);

#endif
