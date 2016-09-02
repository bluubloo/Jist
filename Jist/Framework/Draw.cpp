#include "Draw.h"



Draw::Draw()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Setting the OpenGL versions 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Make sure we only use core OpenGL functions, not legacy
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); //Stops the window from being resized

	//Creates the window and ensures it is created. If not cleans up the OpenGL context
	window = glfwCreateWindow(800, 600, "Jist", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	//Checks to make sure glew has been initalised
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}


Draw::~Draw()
{
}

void Draw::Redraw()
{
	//Draw events in here
	glClear(GL_COLOR_BUFFER_BIT);
	DrawTriangle(Point2D(-0.5, 0.5), Point2D(0.0, 0.5), Point2D(0.5, 0.5));
	glfwSwapBuffers(window);
}

void Draw::CheckInput()
{
	if (glfwWindowShouldClose(window))
	{
		glfwTerminate();
		InputSystem().CloseWindow();
		return;
	}
	glfwPollEvents();
}

void Draw::DrawButton(float x, float y, float width, float height, std::string text)
{
}

void Draw::DrawString(float x, float y, float width, float height, std::string text)
{
}

void Draw::DrawRectangle(float x, float y, float width, float height)
{
}

void Draw::DrawEclipse(float centreX, float centreY, float width, float height)
{
}

void Draw::DrawTriangle(Point2D a, Point2D b, Point2D c)
{
	//Take the vertices of the three triangle points and combine them into a single array
	GLfloat *aVertices = a.GetFloats();
	GLfloat *bVertices = b.GetFloats();
	GLfloat *cVertices = c.GetFloats();
	GLfloat vertices[] = { *aVertices, *(aVertices + 1), *(aVertices + 2),
							*bVertices, *(bVertices + 1), *(bVertices + 2),
							*cVertices, *(cVertices + 1), *(cVertices + 2)};
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


}
