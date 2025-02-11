/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	//window dimensions
	const int windowWidth = 512;
	const int windowHeight = 380;
		
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(windowWidth, windowHeight, "Dapper Dasher");

	// rectangle dimensions
	const int width = 50;
	const int height = 80;

	int posX = windowWidth/2;
	int posY = windowHeight - height;
	int velocity = 0;


	SetTargetFPS(60);	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		DrawRectangle(posX,posY,width,height,BLUE);
		posY += velocity;
		// Jumping Mechanics
		if(IsKeyPressed(KEY_SPACE))
		{
			velocity = -10;
		}
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
