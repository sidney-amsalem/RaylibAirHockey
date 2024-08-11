//
// Created by Sidney Amsalem on 8/11/24.
//

#ifndef RAYLIBAIRHOCKEY_GAMELOGIC_H
#define RAYLIBAIRHOCKEY_GAMELOGIC_H

#include "raylib.h"
#include "Player.h"
#include "Puck.h"


class GameLogic {
public:
    GameLogic(const int screenWidth, const int screenHeight);

    void handleInput();

    void updateGame();

    void collision(Player& player, Puck& puck);

    void reset();

    const int getScoreLeft() const;

    const int getScoreRight() const;

    const GameObject& getPlayer1Data() const;

    const GameObject& getPlayer2Data() const;

    const GameObject& getPuckData() const;

    void leftPlayerScores();

    void rightPlayerScores();


private:
    Player player1;
    Player player2;
    Puck puck;
    Rectangle goalLeft;
    Rectangle goalRight;
    int scoreLeft;
    int scoreRight;
};


#endif //RAYLIBAIRHOCKEY_GAMELOGIC_H
