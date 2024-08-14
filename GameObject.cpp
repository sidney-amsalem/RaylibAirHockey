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

// Custom Copy Constructor
GameObject::GameObject(const GameObject& other)
        : screenWidth(other.screenWidth),      // Initialize const members
          screenHeight(other.screenHeight),
          position(other.position),
          velocity(other.velocity),
          radius(other.radius),
          mass(other.mass),
          frictionCoefficient(other.frictionCoefficient),
          color(other.color)
{}

// Custom Assignment Operator
GameObject& GameObject::operator=(const GameObject& other) {
    if (this == &other) return *this;  // Handle self-assignment

    // Since screenWidth and screenHeight are const, they cannot be assigned, only initialized.

    // Assign all other members
    position = other.position;
    velocity = other.velocity;
    radius = other.radius;
    mass = other.mass;
    frictionCoefficient = other.frictionCoefficient;
    color = other.color;

    return *this;
}

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

