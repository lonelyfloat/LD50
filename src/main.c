#include <raylib.h>
#include <ssecs.h>
#include "animations.h"
#include "level.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten/emscripten.h>
#endif

enum GameScreen
{
    GAME_MENU,
    GAME_PLAYING
} currentScreen = GAME_PLAYING;

const int screenWidth = 800;
const int screenHeight = 450;

// Global Data
EntityData entityData;
LevelData levelData = (LevelData){};

// Player Data

Texture2D *playerAnims;

// Enemy Data

Texture2D *laundryAnims;
Texture2D *dishAnims;


void UpdateDrawFrame(void);



int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    InitWindow(screenWidth, screenHeight, "LD50 Game");
    InitEntityData(&entityData, 1, 3, (size_t[]){sizeof(Rectangle), sizeof(Vector2), sizeof(AnimatedTexture)});
    playerAnims = malloc(2 * sizeof(Texture2D));
    playerAnims = (Texture2D []){LoadTexture("assets/player/idle.png"), LoadTexture("assets/player/walk.png")};
    for (int i = 0; i < 1; ++i)
    {
        AddComponent(&entityData, i, 0, ((Vector2){screenWidth/2, screenHeight/2}), Vector2);
        AddComponent(&entityData, i, 2, ((AnimatedTexture){0, playerAnims, ((Vector2){600,600}), 0, 24, 0.3, false}), AnimatedTexture);
    }
    levelData = LoadLevelData("assets/leveldata", (char* []){"assets/bedroomtiles.png", "assets/kitchentiles.png", "assets/helltiles.png"});
    
    #ifndef __EMSCRIPTEN__
        SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            UpdateDrawFrame();
        }

    #else
        emscripten_set_main_loop(UpdateDrawFrame, 0,1);
    #endif
    //--------------------------------------------------------------------------------------


    // De-Initialization
    //--------------------------------------------------------------------------------------
    free(playerAnims);
    FreeEntityData(&entityData);
    FreeLevelData(&levelData);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void UpdateDrawFrame(void)
{
    switch (currentScreen)
    {
    case GAME_MENU:
        // Main game loop
        // Update
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
        break;
    
    case GAME_PLAYING:
        // Main game loop
        // Update
        //----------------------------------------------------------------------------------
        // player animation stuff, get camera working at some point
        if(IsKeyPressed(KEY_LEFT))
        {
            GetComponentFromID(&entityData, 0, 2, AnimatedTexture).flipped = true;
            GetComponentFromID(&entityData, 0, 2, AnimatedTexture).currentFrame = 0;
            GetComponentFromID(&entityData, 0, 2, AnimatedTexture).currentAnim = 1; 
        }
        else if(IsKeyPressed(KEY_RIGHT))
        {
            GetComponentFromID(&entityData, 0, 2, AnimatedTexture).flipped = false;
            GetComponentFromID(&entityData, 0, 2, AnimatedTexture).currentFrame = 0;
            GetComponentFromID(&entityData, 0, 2, AnimatedTexture).currentAnim = 1;
        }
        else if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
        {
            if(GetComponentFromID(&entityData, 0, 2, AnimatedTexture).currentFrame > 7) GetComponentFromID(&entityData, 0, 2, AnimatedTexture).currentFrame = 0;
            GetComponentFromID(&entityData, 0, 2, AnimatedTexture).currentAnim = 0;
   
        }


        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            for (int i = 0; i < entityData.componentData[2].count; ++i)
            {
                if(HasComponent(&entityData, 0, entityData.componentData[2].dense[i]))
                {
                    DrawAnimatedTexture(&entityData, i);
                }
            }
            
        EndDrawing();
        //----------------------------------------------------------------------------------
        break;
    }

}