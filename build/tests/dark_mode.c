#include <gtk/gtk.h>
#include "raylib.h"

// Function to check if the system is using a dark theme
bool isDarkMode() {
    GtkSettings *settings = gtk_settings_get_default();
    gchar *theme_name;
    g_object_get(settings, "gtk-theme-name", &theme_name, NULL);
    
    // Check if the theme name contains "dark" (This may vary depending on your theme)
    bool darkMode = (strstr(theme_name, "dark") != NULL);
    
    g_free(theme_name); // Don't forget to free the theme name
    
    return darkMode;
}

int main(void)
{
    // Initialize GTK
    gtk_init(NULL, NULL);
    
    // Initialize Raylib window
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib with Dark Mode Detection");

    // Check if dark mode is enabled
    bool darkModeEnabled = isDarkMode();

    // Set initial colors based on dark mode
    Color backgroundColor = darkModeEnabled ? DARKGRAY : LIGHTGRAY;
    Color textColor = darkModeEnabled ? LIGHTGRAY : DARKGRAY;

    SetTargetFPS(60); // Set the game loop to 60 FPS

    while (!WindowShouldClose()) // Main game loop
    {
        // Update
        if (IsKeyPressed(KEY_SPACE)) // Toggle theme on spacebar press
        {
            darkModeEnabled = !darkModeEnabled;
            backgroundColor = darkModeEnabled ? DARKGRAY : LIGHTGRAY;
            textColor = darkModeEnabled ? LIGHTGRAY : DARKGRAY;
        }

        // Draw
        BeginDrawing();
        ClearBackground(backgroundColor);
        DrawText("Press SPACE to toggle dark mode", 10, 10, 20, textColor);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close the window and OpenGL context

    return 0;
}

