#include "player.h"
#include "envitem.h"
#include "raylib.h"
#define G 400.00
#define HORI_SPEED 150.00
#define JMP_SPEED 250.00

void drawPlayer(Player *player) {
  DrawCircleV(player->position, player->radius, player->color);
}

void movePlayer(Player *player, float delta, ENVItem *envitem,
                int envitemlenght) {
  // Horizontal movement (unchanged)
  if (IsKeyDown(KEY_LEFT))
    player->position.x -= HORI_SPEED * delta;
  else if (IsKeyDown(KEY_RIGHT))
    player->position.x += HORI_SPEED * delta;

  // Check for jumping or moving down
  bool wantToJump = IsKeyDown(KEY_SPACE);
  bool wantToMoveDown = IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_SPACE);
  
  // Jumping (when not trying to move down)
  if (wantToJump && !wantToMoveDown && player->canJump) {
    player->speed = -JMP_SPEED;
    player->canJump = false;
  }

  int hitObstacle = 0;
  bool onGround = false;
  for (int i = 0; i < envitemlenght; i++) {
    ENVItem *ei = envitem + i;
    Vector2 *p = &(player->position);
    
    // Check for collision with ground or platforms
    if (ei->blocking && ei->rect.x <= p->x &&
        ei->rect.x + ei->rect.width >= p->x && ei->rect.y - 15 >= p->y &&
        ei->rect.y - 15 <= p->y + player->speed * delta) {
      
      // If trying to move down and it's not the bottom-most platform, allow passing through
      if (wantToMoveDown && i != 0) {
        continue;
      }
      
      hitObstacle = 1;
      player->speed = 0.0f;
      p->y = ei->rect.y - 15;
      onGround = true;
    }
  }

  if (!hitObstacle) {
    player->position.y += player->speed * delta;
    player->speed += G * delta;
    player->canJump = false;
  } else {
    player->canJump = onGround;
  }

  // If wanting to move down and on a platform, add a downward speed
  if (wantToMoveDown && onGround) {
    player->speed = JMP_SPEED / 2; // Adjust this value to control downward speed
  }
}
