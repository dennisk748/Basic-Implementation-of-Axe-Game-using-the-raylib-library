#include "raylib.h"

//Window Dimensions
int width = 900;
int height  = 450;
//Axe Edges
int leftRecEdge[9];
int rightRecEdge[9];
int upRecEdge[9];
int bottomRecEdge[9];
//Axe Dimensions
Color axeColor = RED;
int recPosX[9] = {90,180,270,360,450,540,630,720,795};
int recPosY[9] = {0,200,400,100,150,300,250,310,50};
int recLength = 50;
int direction[9] = {10,13,9,11,15,7,12,13,15};

void GameOver(){ 
     DrawText("Game Over!!!", 259,150,50,RED);
}
void Winning(){
    DrawText("Hooray!!!, You Won!", 250,150,50,GREEN);
}

void DrawAxes(){

    for(int i = 0; i <= 8; i++)
    {
        leftRecEdge[i] = recPosX[i];
        rightRecEdge[i] = (recPosX[i] + recLength);
        upRecEdge[i] = recPosY[i];
        bottomRecEdge[i] = (recPosY[i] + recLength);

        DrawRectangle(recPosX[i], recPosY[i], recLength, recLength, axeColor);

        recPosY[i] += direction[i];
        if (recPosY[i] > (height - 30) || recPosY[i] < 0)
        {
            direction[i] = -(direction[i]);
        }
    }   
}

int main()
{
    //player coordinates
    int circleCenterX{30};
    int circleCenterY{225}; 
    int circleRadius{25};
    //circle edges
    int leftCircleEdge{circleCenterX - circleRadius};
    int rightCircleEdge{circleCenterX + circleRadius};
    int upCircleEdge{circleCenterY - circleRadius};
    int bottomCircleEdge{circleCenterY + circleRadius};

    
    InitWindow(width,height, "Axe Game");
    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        bool collisionStatus;
        bool collisionStatus2;
        bool collisionStatus3;
        bool collisionStatus4;
        bool collisionStatus5;
        bool collisionStatus6;
        bool collisionStatus7;
        bool collisionStatus8;
        bool collisionStatus9;
        bool collisionStatus10;

        //update edges
        leftCircleEdge = circleCenterX - circleRadius;
        rightCircleEdge = circleCenterX + circleRadius;
        upCircleEdge = circleCenterY - circleRadius;
        bottomCircleEdge = circleCenterY + circleRadius;
        
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus = (bottomRecEdge[0] >= upCircleEdge) &&
                      (upRecEdge[0] <= bottomCircleEdge) &&
                      (rightRecEdge[0] >= leftCircleEdge) &&
                      (leftRecEdge[0] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus2 = (bottomRecEdge[1] >= upCircleEdge) &&
                      (upRecEdge[1] <= bottomCircleEdge) &&
                      (rightRecEdge[1] >= leftCircleEdge) &&
                      (leftRecEdge[1] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus3 = (bottomRecEdge[2] >= upCircleEdge) &&
                      (upRecEdge[2] <= bottomCircleEdge) &&
                      (rightRecEdge[2] >= leftCircleEdge) &&
                      (leftRecEdge[2] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus4 = (bottomRecEdge[3] >= upCircleEdge) &&
                      (upRecEdge[3] <= bottomCircleEdge) &&
                      (rightRecEdge[3] >= leftCircleEdge) &&
                      (leftRecEdge[3] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus5 = (bottomRecEdge[4] >= upCircleEdge) &&
                      (upRecEdge[4] <= bottomCircleEdge) &&
                      (rightRecEdge[4] >= leftCircleEdge) &&
                      (leftRecEdge[4] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus6 = (bottomRecEdge[5] >= upCircleEdge) &&
                      (upRecEdge[5] <= bottomCircleEdge) &&
                      (rightRecEdge[5] >= leftCircleEdge) &&
                      (leftRecEdge[5] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus7 = (bottomRecEdge[6] >= upCircleEdge) &&
                      (upRecEdge[6] <= bottomCircleEdge) &&
                      (rightRecEdge[6] >= leftCircleEdge) &&
                      (leftRecEdge[6] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus8 = (bottomRecEdge[7] >= upCircleEdge) &&
                      (upRecEdge[7] <= bottomCircleEdge) &&
                      (rightRecEdge[7] >= leftCircleEdge) &&
                      (leftRecEdge[7] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus9 = (bottomRecEdge[8] >= upCircleEdge) &&
                      (upRecEdge[8] <= bottomCircleEdge) &&
                      (rightRecEdge[8] >= leftCircleEdge) &&
                      (leftRecEdge[8] <= rightCircleEdge);
            
        }
        for(int i = 0; i <= 8; i++)
        {
            collisionStatus10 = (bottomRecEdge[9] >= upCircleEdge) &&
                      (upRecEdge[9] <= bottomCircleEdge) &&
                      (rightRecEdge[9] >= leftCircleEdge) &&
                      (leftRecEdge[9] <= rightCircleEdge);
            
        }
        if(collisionStatus || collisionStatus2 || collisionStatus3 ||
           collisionStatus4 || collisionStatus5 || collisionStatus6 || 
           collisionStatus7 || collisionStatus8 || collisionStatus9 || collisionStatus10){
        GameOver();
        }else
        {
            //game logic begins
            DrawCircle(circleCenterX,circleCenterY,circleRadius,BLACK);
            DrawAxes();

            if(circleCenterX >= (width - circleRadius)){
                Winning();
            }

            //move the circle
            if(circleCenterX < width && (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))){
                circleCenterX += 10;
            }else if (circleCenterX > circleRadius && (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))){
                circleCenterX -= 10;
            }
            //Game Logic Ends
        }
        EndDrawing();
    }
    
}