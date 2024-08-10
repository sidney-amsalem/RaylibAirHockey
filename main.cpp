#include "raylib.h"
#include "Player.h"
#include "Puck.h"

void Reset(Player& player1, Player& player2, Puck& puck){
    puck.reset();
    player1.reset();
    player2.reset();
}

void DrawTime(){
    int seconds = (int) GetTime() % 60;
    int minutes = (int) GetTime() / 60;
    DrawText(TextFormat("Time: %i : %i", minutes,seconds),0,0,30,BLACK);
}

void DrawScore(const int leftScore, const int rightScore, const int screenWidth){
    int fontSize = 50;
    int textSize = MeasureText(TextFormat("%i - %i", leftScore, rightScore), fontSize);
    DrawText(TextFormat("%i - %i", leftScore, rightScore),(screenWidth/2) - (textSize/2) ,0,fontSize,BLACK);
}

void DrawBorder(const int screenWidth, const int screenHeight){


    DrawRectangle(screenWidth/2 - 15, 0, 30, screenHeight, ORANGE);
    DrawCircle(screenWidth/2, screenHeight/2, 150.0f, ORANGE);
    DrawCircle(screenWidth/2, screenHeight/2, 120.0f, WHITE);
    DrawCircle(30, screenHeight/2, 180.0f, ORANGE);
    DrawCircle(30, screenHeight/2, 150.0f, WHITE);
    DrawCircle(screenWidth-30, screenHeight/2, 180.0f, ORANGE);
    DrawCircle(screenWidth-30, screenHeight/2, 150.0f, WHITE);
    DrawRectangle(0, 0, screenWidth, 30, ORANGE);
    DrawRectangle(0, screenHeight-30, screenWidth, 30, ORANGE);
    DrawRectangle(0, 0, 30, screenHeight, ORANGE);
    DrawRectangle(screenWidth-30, 0, 30, screenHeight, ORANGE);


    for (int i = 0; i <= screenWidth; i += 100){
        for (int j = 0; j <= screenHeight; j += 100){
            DrawCircle(i, j, 2.0f, GRAY);
        }
    }
}



void Collision(Player& player, Puck& puck){
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

int main(){
    Color white = {255, 255, 255, 255};

    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Air Hockey");

    SetTargetFPS(60);

    Player player1 = Player::CreateLeftPlayer(screenWidth, screenHeight);
    Player player2 = Player::CreateRightPlayer(screenWidth, screenHeight);
    Puck puck = Puck(screenWidth, screenHeight);
    Rectangle goalLeft = {0, (float)(screenHeight-150)/2, 20.0f, 150.0f};
    Rectangle goalRight = {screenWidth-20.0f, (float)(screenHeight-150)/2, 20.0f, 150.0f};

    int leftScore, rightScore;

    while(WindowShouldClose() == false){

        DrawTime();
        DrawBorder(screenWidth, screenHeight);
        DrawScore(leftScore, rightScore, screenWidth);

        if (IsKeyDown(KEY_D)) player1.accelerate((Vector2){0.6,0});
        if (IsKeyDown(KEY_A)) player1.accelerate((Vector2){-0.6,0});
        if (IsKeyDown(KEY_W)) player1.accelerate((Vector2){0,-0.6});
        if (IsKeyDown(KEY_S)) player1.accelerate((Vector2){0,0.6});

        if (IsKeyDown(KEY_RIGHT)) player2.accelerate((Vector2){0.6,0});
        if (IsKeyDown(KEY_LEFT)) player2.accelerate((Vector2){-0.6,0});
        if (IsKeyDown(KEY_UP)) player2.accelerate((Vector2){0,-0.6});
        if (IsKeyDown(KEY_DOWN)) player2.accelerate((Vector2){0,0.6});



        if(CheckCollisionCircles(player1.getPosition(), player1.getRadius(), puck.getPosition(), puck.getRadius())){
            Collision(player1, puck);
        }
        else if(CheckCollisionCircles(player2.getPosition(), player2.getRadius(), puck.getPosition(), puck.getRadius())){
            Collision(player2, puck);
        }

        //Check for goals
        if (CheckCollisionCircleRec(puck.getPosition(), puck.getRadius(), goalLeft)){
            DrawRectangle((screenWidth/2) - 50, 0, 100, 50, BLUE);
            Reset(player1, player2, puck);
            rightScore++;
        }
        if (CheckCollisionCircleRec(puck.getPosition(), puck.getRadius(), goalRight)){
            DrawRectangle((screenWidth/2) - 50, 0, 100, 50, RED);
            Reset(player1, player2, puck);
            leftScore++;
        }

        player1.update();
        player2.update();
        puck.update();

        BeginDrawing();

        ClearBackground(white);

        player1.drawObject();
        player2.drawObject();
        puck.drawObject();

        EndDrawing();
    }

    CloseWindow();
}