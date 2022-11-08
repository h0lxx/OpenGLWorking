#include "Screen.h"
#include <SDL.h>
#include <Windows.h>
#include <gl/GL.h>
#include <iostream>
#include <math.h>
#include "gl.h"
	SDL_Window* window{ nullptr };
	SDL_GLContext context{ nullptr };

Screen* Screen::Instance()
{
	static Screen* screen = new Screen;
	return screen;
}

bool Screen::Initialize(int width,int height,int positionx , int positiony, float contextInit)
{

	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1)
	{
		std::cout << "SDL did not initialize properly." << std::endl;
		return 0;
		Screen::isAppRunning = false;
	}

	//set OpenGL context and profile using values assigned earlier
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	window = SDL_CreateWindow("OpenGL",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280,
		720,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window)
	{
		std::cout << "SDL window could not be created." << std::endl;
		return 0;
		Screen::isAppRunning = false;
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cout << "OpenGL context could not be created. "
			"The context is either invalid or not supported by your graphics card" << std::endl;
		return 0;
		Screen::isAppRunning = false;
	}

	if (!gladLoaderLoadGL())
	{
		std::cout << "Error loading openGL extensions" << std::endl;
		return false;
	}
	
}

void Screen::Refresh()
{

	glClear(GL_COLOR_BUFFER_BIT);
}

void Screen::SwapBuffer()
{
	SDL_GL_SwapWindow(window);
}

void Screen::Clear()
{
}

void Screen::Shutdown()
{
	SDL_Quit();
}
