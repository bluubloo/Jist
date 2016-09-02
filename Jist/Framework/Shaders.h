#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Shaders
{
public:
	Shaders();
	~Shaders();

	static GLuint SIMPLE_SHADER;

	static void Init();
};

