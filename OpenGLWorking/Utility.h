#pragma once
#include <Windows.h>

class Utility
{

public:


	struct Vector2D
	{
		float x = 0.0f;
		float y = 0.0f;
	};

	struct Vector3D
	{
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
	};
	enum Severity
	{
		Success = 4,
		Default = 7,
		Warning = 6,
		Failed = 2

	};
	static void Instance();
	static void DisplayProfile();
	static void Log(const std::string& message);

	static void CheckGLError();

private:

	static HANDLE consoleHandler;
};

