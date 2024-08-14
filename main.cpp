#include "raylib.h"
#include "GameLogic.h"
#include "Drawing.h"

typedef enum GameState {
    TITLE = 0,
    MENU,
    GAMEPLAY,
    PAUSED
} GameState;


int main(){
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Air Hockey");

    GameState currentScreen = TITLE;

    GameLogic game = GameLogic(screenWidth, screenHeight);

    Drawing drawing = Drawing(screenWidth, screenHeight);

    SetTargetFPS(60);

    while(WindowShouldClose() == false){
        switch(currentScreen)
        {
            case TITLE:
            {
                if (GetTime() > 3){
                    currentScreen = MENU;
                }
            } break;
            case MENU:
            {
                if (IsKeyPressed(KEY_ENTER)){
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                game.handleInput();
                game.updateGame();

                if (IsKeyPressed(KEY_P)){
                    game.saveState();
                    currentScreen = PAUSED;
                }
            } break;
            case PAUSED:
            {
                if (IsKeyPressed(KEY_P)){
                    game.restoreState();
                    currentScreen = GAMEPLAY;
                }
            } break;
            default: break;
        }

        BeginDrawing();

        switch(currentScreen)
        {
            case TITLE:
            {
                drawing.DrawTitleScreen();
            } break;
            case MENU:
            {
                drawing.DrawMenuScreen();
            } break;
            case GAMEPLAY:
            {
                drawing.DrawMap(screenWidth, screenHeight);
                drawing.DrawScore(game.getScoreLeft(), game.getScoreRight(), screenWidth);
                drawing.DrawGameObject(game.getPlayer1Data());
                drawing.DrawGameObject(game.getPlayer2Data());
                drawing.DrawGameObject(game.getPuckData());
            } break;
            case PAUSED:
            {
                drawing.DrawMap(screenWidth, screenHeight);
                drawing.DrawScore(game.getScoreLeft(), game.getScoreRight(), screenWidth);
                drawing.DrawGameObject(game.getSavedPlayer1Data());
                drawing.DrawGameObject(game.getSavedPlayer2Data());
                drawing.DrawGameObject(game.getSavedPuckData());
                drawing.DrawPauseScreen();
            } break;
            default: break;
        }

        EndDrawing();
    }

    CloseWindow();
}

