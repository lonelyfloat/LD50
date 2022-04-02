#ifndef H_ANIMATIONS
#define H_ANIMATIONS

#include <raylib.h>
#include <ssecs.h>

typedef struct AnimatedTexture
{
    Texture2D texture;
    Vector2 size;
    int currentFrame;
    int fps;
} AnimatedTexture;

void DrawAnimatedTexture(EntityData* data, EntityID id);

#endif