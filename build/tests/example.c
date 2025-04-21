#include "raylib.h"

int main(void)
{
    // Initialize window
    InitWindow(800, 600, "Raylib Border Example");

    // Set up the color for the border
    Color borderColor = RED;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Start drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw a border around the entire screen
        DrawRectangleLines(0, 0, GetScreenWidth(), GetScreenHeight(), borderColor);

        // End drawing
        EndDrawing();
    }

    // Close the window and OpenGL context
    CloseWindow();

    return 0;
}

