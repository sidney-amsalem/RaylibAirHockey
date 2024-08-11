//
// Created by Sidney Amsalem on 8/10/24.
//

#include "GameObject.h"

GameObject::GameObject(const int screenWidth, const int screenHeight, Vector2 position, const int radius, const int mass, const float frictionCoefficient, const Color color)
        : screenWidth(screenWidth),
          screenHeight(screenHeight),
          position(position),
          velocity({0,0}),
          radius(radius),
          mass(mass),
          frictionCoefficient(frictionCoefficient),
          color(color)
{}

const Vector2 GameObject::getPosition() const{
    return position;
}

const Vector2 GameObject::getVelocity() const {
    return velocity;
}

const int GameObject::getMass() const{
    return mass;
}

const int GameObject::getRadius() const{
    return radius;
}

const float GameObject::getFrictionCoefficient() const {
    return frictionCoefficient;
}

void GameObject::setVelocity(Vector2 newVelocity) {
    velocity = newVelocity;
}

void GameObject::setPosition(Vector2 newPosition) {
    position = newPosition;
}

Color const GameObject::getColor() const{
    return color;
}

