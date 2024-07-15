#include "camera.h"
#include <math.h>

void UpdateCameraCenterInsideMap(Camera2D *camera, Player *player, ENVItem *envItems, int envItemsLength, float delta, int width, int height){

    camera->target = player->position;
    camera->offset = (Vector2){ width/2.0f, height/2.0f };
    float minX = 1000, minY = 1000, maxX = -1000, maxY = -1000;

    for (int i = 0; i < envItemsLength; i++)
    {
        ENVItem *ei = envItems + i;
        minX = fminf(ei->rect.x, minX);
        maxX = fmaxf(ei->rect.x + ei->rect.width, maxX);
        minY = fminf(ei->rect.y, minY);
        maxY = fmaxf(ei->rect.y + ei->rect.height, maxY);
    }

    Vector2 max = GetWorldToScreen2D((Vector2){ maxX, maxY }, *camera);
    Vector2 min = GetWorldToScreen2D((Vector2){ minX, minY }, *camera);

    if (max.x < width) camera->offset.x = width - (max.x - width/2.0);
    if (max.y < height) camera->offset.y = height - (max.y - height/2.0);
    if (min.x > 0) camera->offset.x = width/2.0 - min.x;
    if (min.y > 0) camera->offset.y = height/2.0 - min.y;
}
