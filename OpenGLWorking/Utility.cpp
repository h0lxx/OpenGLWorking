#include "Utility.h"
#include "gl.h"
#include <iostream>



HANDLE Utility::consoleHandler{ nullptr };






void Utility::DisplayProfile()
{

	std::cout << glGetString(GL_VENDOR) << std::endl;
	std::cout << glGetString(GL_RENDER) << std:: endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;





}

void Utility::CheckGLError()
{
	//check if an error occurred and store its value
	GLenum errorValue = glGetError();

	//use your Log() function internally here


}
