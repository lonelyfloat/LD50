#include <raylib.h>
#include <ssecs.h>
#include "animations.h"

#ifdef __EMSCRIPTEN__
    #include <emscripten/emscripten.h>
#endif

enum GameScreen
{
    GAME_MENU,
    GAME_PLAYING
} currentScreen;

const int screenWidth = 800;
const int screenHeight = 450;

EntityData entityData;
void UpdateDrawFrame(void);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    InitWindow(screenWidth, screenHeight, "LD50 Game");
    InitEntityData(&entityData, 50, 2, (size_t[]){sizeof(Vector2), sizeof(AnimatedTexture)});
    for (int i = 0; i < 50; ++i)
    {
        AddComponent(&entityData, i, 0, ((Vector2){screenWidth/2, screenHeight/2}), Vector2);
    }
    
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
    FreeEntityData(&entityData);
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
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
        break;
    }

}