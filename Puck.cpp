//
// Created by Sidney Amsalem on 8/9/24.
//

#include "Puck.h"

Puck::Puck(const int screenWidth, const int screenHeight)
        : GameObject(screenWidth, screenHeight, {(float)screenWidth/2,(float)screenHeight/2}, 50, 3, 0.99, BLACK)
{}

void Puck::update() {
    Vector2 futurePosition = Vector2Add(getPosition(), getVelocity());
    Vector2 currPosition = getPosition();
    Vector2 tempVelocity = getVelocity();

    // "Bounce off wall" logic

    // If in bounds on x-axis, then update x-coordinate
    if (futurePosition.x > getRadius() && futurePosition.x < screenWidth - getRadius()){
        currPosition.x = futurePosition.x;
    }

        // If touching bounds, reverse x-component of velocity (bounce off wall)
    else{
        tempVelocity.x = -(tempVelocity.x);
    }

    // If in bounds on y-axis, then update y-coordinate
    if (futurePosition.y > getRadius() && futurePosition.y < screenHeight - getRadius()){
        currPosition.y = futurePosition.y;
    }

        // If touching bounds, reverse y-component of velocity (bounce off wall)
    else{
        tempVelocity.y = -(tempVelocity.y);
    }

    // Applies friction coefficient to the velocity
    Vector2 newVelocity = Vector2Scale(tempVelocity, getFrictionCoefficient());

    // Update velocity and position with new values
    setVelocity(newVelocity);
    setPosition(currPosition);
}


void Puck::reset(){
    Vector2 newPosition = {(float)(screenWidth/2),(float)(screenHeight/2)};
    Vector2 newVelocity = {0,0};

    setPosition(newPosition);
    setVelocity(newVelocity);
}

void Puck::resetLeft(){
    Vector2 newPosition = {(float)(screenWidth/3),(float)(screenHeight/2)};
    Vector2 newVelocity = {0,0};

    setPosition(newPosition);
    setVelocity(newVelocity);
}

void Puck::resetRight(){
    Vector2 newPosition = {(float)(2*screenWidth/3),(float)(screenHeight/2)};
    Vector2 newVelocity = {0,0};

    setPosition(newPosition);
    setVelocity(newVelocity);
}