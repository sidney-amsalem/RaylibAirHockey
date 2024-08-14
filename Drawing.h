//
// Created by Sidney Amsalem on 8/11/24.
//

#ifndef RAYLIBAIRHOCKEY_DRAWING_H
#define RAYLIBAIRHOCKEY_DRAWING_H

#include "raylib.h"
#include "GameObject.h"

class Drawing {
public:

    Drawing(const int screenWidth, const int screenHeight);

    void DrawTime();

    void DrawScore(const int scoreLeft, const int scoreRight, const int screenWidth);

    void DrawGameObject(const GameObject& gameObject);

    void DrawMap(const int screenWidth, const int screenHeight);

    void DrawPauseScreen();

    void DrawMenuScreen();

    void DrawTitleScreen();

    void DrawCenteredText(const char *text, int posY, int fontSize, Color color);

private:
    const int screenWidth;
    const int screenHeight;
};


#endif //RAYLIBAIRHOCKEY_DRAWING_H
