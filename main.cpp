#include "raylib.h"
#include "GameLogic.h"
#include "Drawing.h"


int main(){
    Color white = {255, 255, 255, 255};

    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Air Hockey");

    SetTargetFPS(60);

    GameLogic game = GameLogic(screenWidth, screenHeight);

    Drawing drawing = Drawing();

    while(WindowShouldClose() == false){

        game.handleInput();
        game.updateGame();

        BeginDrawing();
            drawing.DrawMap(screenWidth, screenHeight);
            drawing.DrawScore(game.getScoreLeft(), game.getScoreRight(), screenWidth);
            drawing.DrawTime();
            drawing.DrawGameObject(game.getPlayer1Data());
            drawing.DrawGameObject(game.getPlayer2Data());
            drawing.DrawGameObject(game.getPuckData());
        EndDrawing();
    }

    CloseWindow();
}