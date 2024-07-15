#include "camera.h"
#include "envitem.h"
#include "enemy.h"
#include "player.h"
#include "raylib.h"
#include "screen.h"
#include <string.h>

int main() {

  // calling the screen
  struct screenSize screen;
  strcpy(screen.title, "Bouncy game");
  screen.screenWidht = 640;
  screen.screenHeight = 480;

  GetScreen(&screen);

  // calling the player
  struct Player player;
  player.color = MAROON;
  player.speed = 0;
  player.canJump = false;
  player.radius = 5.5f;
  player.position.x = screen.screenWidht / 2.0;
  player.position.y = screen.screenHeight / 2.0;

  //calling the enemy
  struct Enemy enemy;
  enemy.side.x = 17.5f;
  enemy.side.y = 17.5f;
  enemy.speed = 0;
  enemy.position.x = screen.screenWidht / 1.1;
  enemy.position.y = screen.screenHeight / 10.5;
  enemy.color = MAROON;
  enemy.canJump = false;

  // object envitem

  struct ENVItem envItem[] = {
      {{0, 400, 1000, 200}, 1, RED},     {{0, 0, 1000, 400}, 0, LIGHTGRAY},
      {{300, 250, 400, 10}, 1, MAGENTA}, {{250, 300, 100, 10}, 1, RED},
      {{650, 220, 100, 10}, 1, GRAY},    {{850, 200, 100, 5}, 1, BLUE},
      {{150, 350, 100, 10}, 1, GRAY},
  };

  // camera
  Camera2D camera;
  camera.target = player.position;
  camera.offset =
      (Vector2){screen.screenWidht / 2.0f, screen.screenHeight / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  int envitemlenght = sizeof(envItem) / sizeof(envItem[0]);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    float deltatime = GetFrameTime();
    movePlayer(&player, deltatime, envItem, envitemlenght);
    UpdateCameraCenterInsideMap(&camera, &player, envItem, envitemlenght,
                                deltatime, screen.screenWidht,
                                screen.screenHeight);

    BeginDrawing();
    ClearBackground(DARKGRAY);

    BeginMode2D(camera); // Begin 2D mode with the camera
    for (int i = 0; i < envitemlenght; i++) {
      drawObstacle(&envItem[i]);
    }
    drawPlayer(&player);
    drawEnemy(&enemy);
    moveEnemy(&enemy, deltatime, envItem, envitemlenght);
    EndMode2D(); // End 2D mode with the camera

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
