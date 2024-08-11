//
// Created by Sidney Amsalem on 8/8/24.
//

#ifndef RAYLIBAIRHOCKEY_PLAYER_H
#define RAYLIBAIRHOCKEY_PLAYER_H

#include "raylib.h"
#include "raymath.h"
#include "GameObject.h"

class Player : public GameObject{
public:

    static Player CreateLeftPlayer(const int screenWidth, const int screenHeight);

    static Player CreateRightPlayer(const int screenWidth, const int screenHeight);

    void accelerate(Vector2 x);

    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void update() override;

    void reset() override;


private:
    enum SpawnLocation{
        LEFT,
        RIGHT
    };

    Player(const int screenWidth, const int screenHeight, const Color playerColor, SpawnLocation spawnLocation);

    SpawnLocation spawnLocation;
    const float movementSpeed;
};

#endif //RAYLIBAIRHOCKEY_PLAYER_H
