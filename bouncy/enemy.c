#include "enemy.h"
#include "envitem.h"
#include <raylib.h>
#define G 400.00
#define HORI_SPEED 50.00



void drawEnemy(Enemy *enemy){
  DrawRectangleV(enemy->position, enemy->side, enemy->color);
}

void moveEnemy(Enemy *enemy, float delta, ENVItem *envitem, int envitemlenght){
  enemy->position.x -= HORI_SPEED * delta;
  int hitObstacle = 0;
  bool onGround = false;
    for (int i = 0; i < envitemlenght; i ++){
    ENVItem *ei = envitem + i;
    Vector2 *p = &(enemy->position);
    
    // Check for collision with ground or platforms
    if (ei->blocking && ei->rect.x <= p->x &&
        ei->rect.x + ei->rect.width >= p->x && ei->rect.y - 15 >= p->y &&
        ei->rect.y - 15 <= p->y + enemy->speed * delta) {
      
      hitObstacle = 1;
      enemy->speed = 0.0f;
      p->y = ei->rect.y - 15;
      onGround = true;
    }
  }

  if (!hitObstacle) {
    enemy->position.y += enemy->speed * delta;
    enemy->speed += G * delta;
    enemy->canJump = false;
  } else {
    enemy->canJump = onGround;
  }
  }
