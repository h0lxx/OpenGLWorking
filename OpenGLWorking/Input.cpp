#include "Input.h"
#include "Screen.h"
#include <Windows.h>
#include <gl/GL.h>
#include <iostream>
#include <SDL.h>
#include <math.h>
#include"Utility.h"



SDL_Event events;
Screen screen;

void Input::Inputs()
{
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{

			//clicking the top right windows 'X'
		case SDL_QUIT:
		{
			screen.isAppRunning = false;
			break;
		}

		case SDL_KEYDOWN:
		{
			//char key = events.key.keysym.sym;
			//std::cout << key << std::endl;
			break;
		}

		case SDL_KEYUP:
		{
			char key = events.key.keysym.sym;
			std::cout << key << std::endl;
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			switch (events.button.button)
			{

			case SDL_BUTTON_LEFT:
			{
				std::cout << "Left mouse button was clicked." << std::endl;
				break;
			}

			case SDL_BUTTON_RIGHT:
			{
				std::cout << "Right mouse button was clicked." << std::endl;
				break;
			}

			case SDL_BUTTON_MIDDLE:
			{
				std::cout << "Middle mouse button was clicked." << std::endl;
				break;
			}

			}

			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			switch (events.button.button)
			{

			case SDL_BUTTON_LEFT:
			{
				std::cout << "Left mouse button was released." << std::endl;
				break;
			}

			case SDL_BUTTON_RIGHT:
			{
				std::cout << "Right mouse button was released." << std::endl;
				break;
			}

			case SDL_BUTTON_MIDDLE:
			{
				std::cout << "Middle mouse button was released." << std::endl;
				break;
			}

			}

			break;
		}

		case SDL_MOUSEMOTION:
		{
			//mouse movements 
			auto mouseMotionX = events.motion.xrel;
			auto mouseMotionY = events.motion.yrel;

			//mouse cursor position in screen space
			auto mousePositionX = events.motion.x;
			auto mousePositionY = events.motion.y;

			//mouse cursor position in NDC (normalized device coordinate) space
			auto mousePositionXNDC = mousePositionX / 1280.0f * 2.0f - 1.0f;
			auto mousePositionYNDC = mousePositionY / 720.0f * 2.0f - 1.0f;

			screen.position.x = mousePositionXNDC;
			screen.position.y = -mousePositionYNDC;

			break;
		}

		case SDL_MOUSEWHEEL:
		{
			auto wheelMotion = events.wheel.y;
			std::cout << wheelMotion << std::endl;

			/*scale.x += wheelMotion * 0.01f;
			scale.y += wheelMotion * 0.01f;*/

			break;
		}

		}

	}
}