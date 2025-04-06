#include <raylib.h>
#include <stdio.h>

int main()
{
	Sound	sound;
	Music	music;

	//create the window
	InitWindow(800, 450, "raylib window");

	InitAudioDevice();
	sound = LoadSound("sound.ogg");
	music = LoadMusicStream("sound.mp3");

	while (!WindowShouldClose())
	{
		UpdateMusicStream(music);
		if (IsKeyPressed(' '))
		{
			//StopMusicStream(music);	
			PlayMusicStream(music);	
		}
		if (IsKeyPressed('Q'))
		{
			printf("hey\n");
			StopMusicStream(music);	
		}

		BeginDrawing();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			PlaySound(sound);

		DrawText("raylib window",  190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}

	CloseAudioDevice();
	//close the window
	CloseWindow();
	return (0);

}
