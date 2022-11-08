#pragma once
#include "gl.h"
class Screen

{

public:

bool isAppRunning = true;
static Screen* Instance();


	struct Position
	{
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

	};


	
	Position position = { 0.0f, 0.0f, 0.0f };

	bool Initialize(int width, int height, int positionx, int positiony, float contextInit);
	void Refresh();
	void SwapBuffer();
	void Clear();
	void Shutdown();



	/*Screen() {}
	Screen(const Screen&);
	Screen& operator = (const Screen&);*/


private:

	/*
	SDL_Window* window{ nullptr };
	SDL_GLContext context{ nullptr };*/





};

