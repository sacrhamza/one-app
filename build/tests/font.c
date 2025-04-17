/*******************************************************************************************
 *
 *   raylib [text] example - Font loading
 *
 *   Example complexity rating: [★☆☆☆] 1/4
 *
 *   NOTE: raylib can load fonts from multiple input file formats:
 *
 *     - TTF/OTF > Sprite font atlas is generated on loading, user can configure
 *                 some of the generation parameters (size, characters to include)
 *     - BMFonts > Angel code font fileformat, sprite font image must be provided
 *                 together with the .fnt file, font generation cna not be configured
 *     - XNA Spritefont > Sprite font image, following XNA Spritefont conventions,
 *                 Characters in image must follow some spacing and order rules
 *
 *   Example originally created with raylib 1.4, last time updated with raylib 3.0
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2016-2025 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [text] example - font loading");

	// Define characters to draw
	// NOTE: raylib supports UTF-8 encoding, following list is actually codified as UTF8 internally
	const char msg[256] = "brave browser vsocde brave ";

	Font fontBm = LoadFontEx("/home/hsacr/COMMON_CORE/one-app/build/assets/fonts/JetBrainsMonoNerdFont-Regular.ttf", 20, 0, 250);

	SetTextLineSpacing(16);         // Set line spacing for multiline text (when line breaks are included '\n')

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-seco

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawTextEx(fontBm, msg, (Vector2){ 20.0f, 300.0f }, (float)fontBm.baseSize, 2, MAROON);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
