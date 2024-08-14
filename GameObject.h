//
// Created by Sidney Amsalem on 8/10/24.
//

#ifndef RAYLIBAIRHOCKEY_GAMEOBJECT_H
#define RAYLIBAIRHOCKEY_GAMEOBJECT_H

#include "raylib.h"
#include "raymath.h"

class GameObject {
protected:
    GameObject(const int screenWidth, const int screenHeight, Vector2 position, const int radius, const int mass, const float frictionCoefficient, const Color color);

    // Copy constructor
    GameObject(const GameObject& other);

    // Assignment operator
    GameObject& operator=(const GameObject& other);

    /**
     * @brief Sets the GameObject position to a given value
     *
     * @param newPosition
     */
    void setPosition(Vector2 newPosition);


    const int screenWidth;
    const int screenHeight;

public:

    /**
     * @brief Updates the GameObject position using the current velocity and game bounds. Updates
     * velocity using friction coefficient
     */
    virtual void update() = 0;

    const Vector2 getPosition() const;

    const Vector2 getVelocity() const;

    const int getMass() const;

    const int getRadius() const;

    const Color getColor() const;

    const float getFrictionCoefficient() const;

    /**
     * @brief Sets the GameObject velocity to a given value
     *
     * @param newVelocity
     */
    void setVelocity(Vector2 newVelocity);

    virtual void reset() = 0;

private:
    Vector2 position;
    Vector2 velocity;
    int radius;
    int mass;
    float frictionCoefficient;
    Color color;
};


#endif //RAYLIBAIRHOCKEY_GAMEOBJECT_H
