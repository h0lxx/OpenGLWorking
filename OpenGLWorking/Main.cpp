//#include <Windows.h>
#include "gl.h"
#include "Screen.h"
#include <iostream>
#include <SDL.h>
#include "Input.h"
#include <math.h>
#include "Utility.h"



Screen screen2;
Input input;

Utility::Vector2D scale = { 1.0f, 1.0f };
Utility::Vector3D position = { 0.0f, 0.0f, 0.0f };


int main(int argc, char* argv[])
{
	

	static float num = 0.0f;
	Screen::Instance()->Initialize(1280, 720, 320, 180, 4.5);
	while (screen2.isAppRunning != false)
	{
		Screen::Instance()->Clear();
		Screen::Instance()->SwapBuffer();
		input.Inputs();
		
		glBegin(GL_QUADS);

		//position.x = cos(num);
		//position.y = sin(num);

		//top left vertex
		glColor3f(std::abs(sin(num)), 1.0f, 0.0f);
		glVertex3f(position.x - scale.x, position.y + scale.y, position.z + 0.0f);

		//top right vertex
		glColor3f(std::abs(cos(num)), 0.0f, 0.0f);
		glVertex3f(position.x + scale.x, position.y + scale.y, position.z + 0.0f);

		//bottom right vertex
		glColor3f(0.0f, std::abs(cos(num)), 0.0f);
		glVertex3f(position.x + scale.x, position.y - scale.y, position.z + 0.0f);

		//bottom left vertex
		glColor3f(0.0f, 0.0f, std::abs(sin(num)));
		glVertex3f(position.x - scale.x, position.y - scale.y, position.z + 0.0f);

		glEnd();
		
		
		

	}

	Screen::Instance()->Shutdown();
	
	return 0;
}