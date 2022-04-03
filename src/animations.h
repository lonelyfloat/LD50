#ifndef H_ANIMATIONS
#define H_ANIMATIONS

#include <raylib.h>
#include <ssecs.h>

typedef struct AnimatedTexture
{
    int currentAnim;
    Texture2D *textures;
    Vector2 size;
    int currentFrame;
    int fps;
    float scale;
    bool flipped;
    Vector2 offsets;
} AnimatedTexture;

void DrawAnimatedTexture(EntityData* data, EntityID id);

#endif