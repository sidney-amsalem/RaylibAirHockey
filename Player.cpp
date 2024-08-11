//
// Created by Sidney Amsalem on 8/8/24.
//
#include "Player.h"

Player Player::CreateLeftPlayer(const int screenWidth, const int screenHeight) {
    return Player(screenWidth, screenHeight, RED, LEFT);
}

Player Player::CreateRightPlayer(const int screenWidth, const int screenHeight) {
    return Player(screenWidth, screenHeight, BLUE, RIGHT);
}

Player::Player(const int screenWidth, const int screenHeight, const Color color, const SpawnLocation spawnLocation)
        : GameObject(screenWidth, screenHeight, {0, 0}, 80, 12, 0.97, color), // Initialize GameObject base class
          spawnLocation(spawnLocation), // Initialize derived class members
          movementSpeed(0.6)
{
    Vector2 playerPosition;

    if (spawnLocation == LEFT){
        playerPosition = (Vector2){(float)screenWidth*0.1f, (float)screenHeight/2};
    }
    else if (spawnLocation == RIGHT){
        playerPosition = (Vector2){(float)screenWidth*0.9f, (float)screenHeight/2};
    }

    // Set the position using the base class method
    setPosition(playerPosition);
}


void Player::moveLeft(){
    Vector2 tempVelocity = getVelocity();
    tempVelocity.x -= movementSpeed;

    setVelocity(tempVelocity);
}

void Player::moveRight(){
    Vector2 tempVelocity = getVelocity();
    tempVelocity.x += movementSpeed;

    setVelocity(tempVelocity);
}

void Player::moveUp(){
    Vector2 tempVelocity = getVelocity();
    tempVelocity.y -= movementSpeed;

    setVelocity(tempVelocity);
}

void Player::moveDown(){
    Vector2 tempVelocity = getVelocity();
    tempVelocity.y += movementSpeed;

    setVelocity(tempVelocity);
}

void Player::update() {
    Vector2 futurePosition = Vector2Add(getPosition(), getVelocity());
    Vector2 currPosition = getPosition();
    Vector2 tempVelocity = getVelocity();

    // Boundary logic

    // If left player, confine movement to left side
    if (spawnLocation == LEFT){

        // If in bounds on x-axis, then update x-coordinate
        if (futurePosition.x > getRadius() && futurePosition.x < screenWidth/2 - getRadius()){
            currPosition.x = futurePosition.x;
        }

            // If touching the boundary, set x-component of velocity to 0
        else tempVelocity.x = 0;
    }

        // Right player, confine movement to right side
    else{

        // If in bounds on x-axis, then update x-coordinate
        if (futurePosition.x > screenWidth/2 + getRadius() && futurePosition.x < screenWidth - getRadius()){
            currPosition.x = futurePosition.x;
        }

            // If touching the boundary, set x-component of velocity to 0
        else tempVelocity.x = 0;
    }


    // If in bounds on y-axis, then update y-coordinate
    if (futurePosition.y > getRadius() && futurePosition.y < screenHeight - getRadius()){
        currPosition.y = futurePosition.y;
    }

        // If touching top/bottom border, set y-component of velocity to 0
    else{
        tempVelocity.y = 0;
    }

    // Applies friction coefficient to the velocity
    Vector2 newVelocity = Vector2Scale(tempVelocity, getFrictionCoefficient());

    // Update velocity and position with new values
    setVelocity(newVelocity);
    setPosition(currPosition);
}

void Player::reset(){
    Vector2 newPosition;
    Vector2 newVelocity = {0,0};

    if (spawnLocation == LEFT){
        newPosition = (Vector2){(float)screenWidth*0.1f,(float)screenHeight/2};
    }
    else if (spawnLocation == RIGHT){
        newPosition = (Vector2){(float)screenWidth*0.9f,(float)screenHeight/2};
    }
    setPosition(newPosition);
    setVelocity(newVelocity);
}