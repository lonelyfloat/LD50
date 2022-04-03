#include "animations.h"
#include "utils.h"

void DrawAnimatedTexture(EntityData* data, EntityID id)
{
    if(RunAtFPS(GetComponentFromID(data, id, 1, AnimatedTexture).fps))
    {
        if(GetComponentFromID(data, id, 1, AnimatedTexture).currentFrame < (GetComponentFromID(data, id, 1, AnimatedTexture).textures[GetComponentFromID(data, id, 1, AnimatedTexture).currentAnim].width/GetComponentFromID(data, id, 1, AnimatedTexture).size.x))
        {
            ++GetComponentFromID(data, id, 1, AnimatedTexture).currentFrame;
        }   
        else
            GetComponentFromID(data, id, 1, AnimatedTexture).currentFrame = 0;
    }
    
    DrawTexturePro(GetComponentFromID(data, id, 1, AnimatedTexture).textures[GetComponentFromID(data, id, 1, AnimatedTexture).currentAnim],
    (Rectangle){GetComponentFromID(data, id, 1, AnimatedTexture).currentFrame * GetComponentFromID(data, id, 1, AnimatedTexture).size.x, 0, 
    GetComponentFromID(data, id, 1, AnimatedTexture).size.x * (GetComponentFromID(data, id, 1, AnimatedTexture).flipped ? -1 : 1), GetComponentFromID(data, id, 1, AnimatedTexture).size.y
    }, 
    (Rectangle){GetComponentFromID(data, id, 0, Vector2).x, GetComponentFromID(data, id, 0, Vector2).y, 
    GetComponentFromID(data, id, 1, AnimatedTexture).size.x
    * (GetComponentFromID(data, id, 1, AnimatedTexture).scale),
     GetComponentFromID(data, id, 1, AnimatedTexture).size.y
    * GetComponentFromID(data, id, 1, AnimatedTexture).scale}, 
    (Vector2){0,0}, 0, WHITE
    );
}