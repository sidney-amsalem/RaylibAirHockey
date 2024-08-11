//
// Created by Sidney Amsalem on 8/9/24.
//

#ifndef RAYLIBAIRHOCKEY_PUCK_H
#define RAYLIBAIRHOCKEY_PUCK_H

#include "raylib.h"
#include "GameObject.h"

class Puck : public GameObject{
public:
    Puck(const int screenWidth, const int screenHeight);

    void update() override;

    void reset() override;

    void resetLeft();

    void resetRight();
};


#endif //RAYLIBAIRHOCKEY_PUCK_H
