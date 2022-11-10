/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib-cpp.hpp"

#include <vector>

struct Circle
{
    raylib::Vector2 center;
    float radius;
    raylib::Color color;
};

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "Hello Raylib-cpp");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //--------------------------------------------------------------------------------------
    
    // one vector of pointers per type of things
    std::vector<Circle *> circles;

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        // spawning new circles at runtime
        if (IsMouseButtonPressed(0))
        {
            raylib::Vector2 mousePos = raylib::Mouse::GetPosition();

            Circle * newCirc = new Circle();
            newCirc->center = mousePos;
            newCirc->radius = GetRandomValue(10, 30);
            newCirc->color = raylib::Color::Blue();

            circles.push_back(newCirc);
        }

        // remove the circle underneath the player's cursor
        if (IsMouseButtonPressed(1))
        {
            raylib::Vector2 mousePos = raylib::Mouse::GetPosition();

            int indexToDelete = -1;

            // which circle?
            for (int i = 0; i < circles.size(); ++i)
            {
                if (CheckCollisionPointCircle(mousePos, circles[i]->center, circles[i]->radius))
                {
                    indexToDelete = i;
                    break;
                }
            }

            // SWAP WITH THE END AND POP
            if (indexToDelete != -1)
            {
                // swap with the end and pop
                Circle * temp = circles[indexToDelete];

                circles[indexToDelete] = circles[circles.size() - 1];
                circles[circles.size() - 1] = temp;

                delete temp;
                circles.pop_back();
            }

            // FIND AND ERASE
            //if (indexToDelete != -1)
            //{
            //    delete circles[indexToDelete];
            //    circles.erase(circles.begin() + indexToDelete);
            //}
        }

        // remove the last circle at runtime
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            delete circles[circles.size() - 1];
            circles.pop_back();
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        window.ClearBackground(RAYWHITE);

        // draw all the circles we have (whatever number of them we have)
        for (int i = 0; i < circles.size(); ++i)
        {
            DrawCircleV(circles[i]->center, circles[i]->radius, circles[i]->color);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}