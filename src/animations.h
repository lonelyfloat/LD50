#ifndef H_ANIMATIONS
#define H_ANIMATIONS

#include <raylib.h>

typedef struct AnimatedTexture
{
    Texture2D texture;
    Vector2 size;
    int currentFrame;
    int fps;
} AnimatedTexture;

void DrawAnimatedTexture();

#endif