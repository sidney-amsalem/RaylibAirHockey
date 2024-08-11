//
// Created by Sidney Amsalem on 8/11/24.
//

#include "GameLogic.h"

GameLogic::GameLogic(const int screenWidth, const int screenHeight)
    : player1(Player::CreateLeftPlayer(screenWidth, screenHeight)),
    player2(Player::CreateRightPlayer(screenWidth, screenHeight)),
    puck(Puck(screenWidth, screenHeight)),
    goalLeft({0, (float)(screenHeight-170)/2, 30.0f, 170.0f}),
    goalRight({screenWidth-20.0f, (float)(screenHeight-170)/2, 30.0f, 170.0f}),
    scoreLeft(0),
    scoreRight(0)
{}

void GameLogic::handleInput(){
    if (IsKeyDown(KEY_D)) player1.moveRight();
    if (IsKeyDown(KEY_A)) player1.moveLeft();
    if (IsKeyDown(KEY_W)) player1.moveUp();
    if (IsKeyDown(KEY_S)) player1.moveDown();

    if (IsKeyDown(KEY_RIGHT)) player2.moveRight();
    if (IsKeyDown(KEY_LEFT)) player2.moveLeft();
    if (IsKeyDown(KEY_UP)) player2.moveUp();
    if (IsKeyDown(KEY_DOWN)) player2.moveDown();
}

void GameLogic::collision(Player& player, Puck& puck){
    Vector2 playerVelocity = player.getVelocity();
    int playerMass = player.getMass();
    Vector2 puckVelocity = puck.getVelocity();
    int puckMass = puck.getMass();

    Vector2 newPlayerVelocity;
    Vector2 newPuckVelocity;

    newPlayerVelocity.x = (((playerMass - puckMass) * playerVelocity.x) + (2 * puckMass * puckVelocity.x))/(playerMass+puckMass);
    newPuckVelocity.x = (((puckMass - playerMass) * puckVelocity.x) + (2 * playerMass * playerVelocity.x))/(playerMass+puckMass);
    newPlayerVelocity.y = (((playerMass - puckMass) * playerVelocity.y) + (2 * puckMass * puckVelocity.y))/(playerMass+puckMass);
    newPuckVelocity.y = (((puckMass - playerMass) * puckVelocity.y) + (2 * playerMass * playerVelocity.y))/(playerMass+puckMass);

    player.setVelocity(newPlayerVelocity);
    puck.setVelocity(newPuckVelocity);
}

const int GameLogic::getScoreLeft() const{
    return scoreLeft;
}

const int GameLogic::getScoreRight() const{
    return scoreRight;
}

void GameLogic::updateGame() {

    Vector2 futurePuckPosition = Vector2Add(puck.getPosition(), puck.getVelocity());

    // Check for interaction between player and future puck position
    if(CheckCollisionCircles(player1.getPosition(), player1.getRadius(), futurePuckPosition, puck.getRadius())){
        collision(player1, puck);
    }
    else if(CheckCollisionCircles(player2.getPosition(), player2.getRadius(), futurePuckPosition, puck.getRadius())){
        collision(player2, puck);
    }


    // Check for goals



    // Right player scores goal
    if (CheckCollisionCircleRec(puck.getPosition(), puck.getRadius(), goalLeft)){
        rightPlayerScores();
    }

    // Left player scores goal
    if (CheckCollisionCircleRec(puck.getPosition(), puck.getRadius(), goalRight)){
        leftPlayerScores();
    }

    player1.update();
    player2.update();
    puck.update();
}

void GameLogic::reset() {
    player1.reset();
    player2.reset();
    puck.reset();
}

void GameLogic::leftPlayerScores(){
    player1.reset();
    player2.reset();
    puck.resetRight();

    scoreLeft++;
}

void GameLogic::rightPlayerScores() {
    player1.reset();
    player2.reset();
    puck.resetLeft();

    scoreRight++;
}


const GameObject& GameLogic::getPlayer1Data() const {
    return player1;
}

const GameObject& GameLogic::getPlayer2Data() const {
    return player2;
}

const GameObject& GameLogic::getPuckData() const {
    return puck;
}



