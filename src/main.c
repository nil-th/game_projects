#include "raylib.h"

int main()
{

	// Movement Variables
	int _boxDirection = 10, speed = 10;
	int circle_margin = 10, box_maring = 10;
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Window Dimension
	int x_axis = 800, y_axis = 450;
	int circle_x = 250, circle_y = 225, r = 25;
	int rect_x = 400, rect_y = 0, width = 50, height = 50;

	// Create the window and OpenGL context
	InitWindow(x_axis, y_axis, "Hello Raylib");

	// Tell the window that game is Over
	bool collision_with_box = false;

	// game loop
	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// Game Over
		if (collision_with_box)
		{
			DrawText("Game Over!", 400, 200, 20, RED);	
		}
		else{

			// Game Logic
			DrawCircle(circle_x, circle_y, r, BLUE);
			DrawRectangle(rect_x, rect_y, width, height, YELLOW);

			// Moving Box vertically
			rect_y += _boxDirection;
			if (rect_y > 450 || rect_y < 0)
			{
				_boxDirection = -_boxDirection;
            }

				// Circle Horizontal Movements
				if (IsKeyDown(KEY_A) && circle_x - r >= 0)
				{
					circle_x -= speed;
				}

				if (IsKeyDown(KEY_D) && circle_x + r <= x_axis)
				{
					circle_x += speed;
				}

				// Circle and Reactagle Points

				int cL_edge = circle_x - r;
				int cR_edge = circle_x + r;
				int cU_edge = circle_y - r;
				int cD_edge = circle_y + r;

				int xV1 = rect_x, yV1 = rect_y;
				int xV2 = rect_x + width, yV2 = rect_y;
				int xV3 = rect_x, yV3 = rect_y + height;
				int xV4 = rect_x + width, yV4 = rect_y + height;

				// Collision Detection

				if ( ((cR_edge >= rect_x) && (cL_edge < rect_x)) && ( (cU_edge>=rect_y && cU_edge<=yV3) || (cD_edge>=rect_y) && (cD_edge<=yV3) ))
				{
					collision_with_box = true;
				}

			}
			// end the frame and get ready for the next one  (display frame, poll input, etc...)
			EndDrawing();
		}
	}
