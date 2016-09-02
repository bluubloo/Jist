#include "Shaders.h"

GLuint Shaders::SIMPLE_SHADER;

Shaders::Shaders()
{
}


Shaders::~Shaders()
{
}

void Shaders::Init()
{
	//Simple Vertex Shader creation
	GLuint simpleVertextShader;
	const char * simpleVertexShaderString[] =
	{
		"#version 330 core													\n"
		"layout (location = 0) in vec3 position;							\n"
		"void main()														\n"
		"{																	\n"
		"	 gl_Position = vec4(position.x, position.y, position.z, 1.0);	\n"
		"}																	\n"
	};
	simpleVertextShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(simpleVertextShader, 1, simpleVertexShaderString, NULL);
	glCompileShader(simpleVertextShader);
	//Test for compilation errors
	GLint success;
	GLchar info[512];
	glGetShaderiv(simpleVertextShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(simpleVertextShader, 512, NULL, info);
		std::cout << "Vertex shader compilation error: " << info << std::endl;
	}

	//Simple Fragment Shader compilation
	GLuint simpleFragementShader;
	const char * simpleFragmentShaderString[] =
	{
		"#version 330 core													\n"
		"out vec4 color;													\n"
		"void main()														\n"
		"{																	\n"
		"	 color = vec4(1.0f, 0.5f, 0.2f, 1.0f);							\n"
		"}																	\n"
	};
	simpleFragementShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(simpleFragementShader, 1, simpleFragmentShaderString, NULL);
	glCompileShader(simpleFragementShader);
	//Test for compilation errors
	glGetShaderiv(simpleFragementShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(simpleFragementShader, 512, NULL, info);
		std::cout << "Fragment shader compilation error: " << info << std::endl;
	}

	//Create shader program
	Shaders::SIMPLE_SHADER = glCreateProgram();
	glAttachShader(Shaders::SIMPLE_SHADER, simpleVertextShader);
	glAttachShader(Shaders::SIMPLE_SHADER, simpleFragementShader);
	glLinkProgram(Shaders::SIMPLE_SHADER);
	//Test for compilation errors
	glGetShaderiv(Shaders::SIMPLE_SHADER, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(Shaders::SIMPLE_SHADER, 512, NULL, info);
		std::cout << "Shader program compilation error: " << info << std::endl;
	}
	glDeleteShader(simpleFragementShader);
	glDeleteShader(simpleVertextShader);
}
