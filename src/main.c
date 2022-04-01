#include <raylib.h>

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


void UpdateDrawFrame(void);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    InitWindow(screenWidth, screenHeight, "LD50 Game");
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