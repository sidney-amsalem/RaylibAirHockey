//
// Created by Sidney Amsalem on 8/11/24.
//

#include "Drawing.h"

Drawing::Drawing(const int screenWidth, const int screenHeight)
    : screenWidth(screenWidth),
    screenHeight(screenHeight)
{}

void Drawing::DrawTime(){
    int seconds = (int) GetTime() % 60;
    int minutes = (int) GetTime() / 60;
    DrawText(TextFormat("Time: %i : %i", minutes,seconds),0,0,30,BLACK);
}

void Drawing::DrawScore(const int scoreLeft, const int scoreRight, const int screenWidth){
    int fontSize = 50;
    int textSize = MeasureText(TextFormat("%i - %i", scoreLeft, scoreRight), fontSize);
    DrawText(TextFormat("%i - %i", scoreLeft, scoreRight),(screenWidth/2) - (textSize/2) ,0,fontSize,BLACK);
}

void Drawing::DrawGameObject(const GameObject& gameObject){
    Vector2 position = gameObject.getPosition();
    Color color = gameObject.getColor();
    int radius = gameObject.getRadius();
    DrawCircleV(position, radius, color);
}

void Drawing::DrawMap(const int screenWidth, const int screenHeight){

    // Border
    ClearBackground(ORANGE);
    DrawRectangle(30, 30, screenWidth-60, screenHeight-60, WHITE);

    // Center divide
    DrawRectangle(screenWidth/2 - 15, 0, 30, screenHeight, ORANGE);

    // Center circle
    DrawCircle(screenWidth/2, screenHeight/2, 150.0f, ORANGE);
    DrawCircle(screenWidth/2, screenHeight/2, 120.0f, WHITE);

    // Left goal
    DrawCircle(30, screenHeight/2, 180.0f, ORANGE);
    DrawCircle(30, screenHeight/2, 150.0f, WHITE);
    DrawRectangle(0, 0, 30, screenHeight, ORANGE);

    // Right goal
    DrawCircle(screenWidth-30, screenHeight/2, 180.0f, ORANGE);
    DrawCircle(screenWidth-30, screenHeight/2, 150.0f, WHITE);
    DrawRectangle(screenWidth-30, 0, 30, screenHeight, ORANGE);

    // Air holes
    for (int i = 0; i <= screenWidth; i += 100){
        for (int j = 0; j <= screenHeight; j += 100){
            DrawCircle(i, j, 2.0f, GRAY);
        }
    }
}

void Drawing::DrawPauseScreen(){
    DrawCenteredText("PAUSED", 3*screenHeight/7, 60, BLACK);
}

void Drawing::DrawMenuScreen(){
    ClearBackground(ORANGE);
    DrawCenteredText("RAYLIB AIR HOCKEY", 2*screenHeight/5, 100, WHITE);
    DrawCenteredText("press ENTER to begin", 2*screenHeight/5 + 100, 60, WHITE);
}

void Drawing::DrawTitleScreen(){
    ClearBackground(BLACK);
    DrawCenteredText("made by Sidney Amsalem", screenHeight/2 - 50, 60, WHITE);
}

void Drawing::DrawCenteredText(const char *text, int posY, int fontSize, Color color){
    int textSize = MeasureText(TextFormat(text), fontSize);
    int center = (screenWidth/2) - (textSize/2);
    DrawText(text, center, posY, fontSize, color);
}