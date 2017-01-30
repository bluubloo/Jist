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

	//Calculate pi
	pi = atan(1) * 4;
}


Draw::~Draw()
{
}

GLFWwindow* Draw::GetWindow()
{
	return window;
}

void Draw::Redraw()
{
	//Draw events in here
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//DrawRectangle(-0.5f, 0.5f, 1.0f, 1.0f);
	Point2D a (50.0f, 25.0f);
	Point2D b (25.0f, 75.0f);
	Point2D c(75.0f, 75.0f);
	DrawTriangle(a, b, c);
	glfwSwapBuffers(window);
}



void Draw::DrawButton(float x, float y, float width, float height, std::string text)
{
}

void Draw::DrawString(float x, float y, float width, float height, std::string text)
{
}

void Draw::DrawRectangle(float x, float y, float width, float height)
{
	GLfloat vertices[] = {	x, y, 0.0f,					//Top left
							x, y - height, 0.0f,		//Bottom left
							x + width, y - height, 0.0f,//Bottom right
							x + width, y, 0.0f};		//Top right

	GLuint indices[] = { 0, 1, 2,
						0, 3, 2 };

	glUseProgram(Shaders::SIMPLE_SHADER);

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Draw::DrawEclipse(float centreX, float centreY, float radius)
{
	
	
}

void Draw::DrawTriangle(Point2D a, Point2D b, Point2D c)
{
	//Take the vertices of the three triangle points and combine them into a single array
	GLfloat vertices[] = {	a.GLGetX(), a.GLGetY(), 0.0f,
							b.GLGetX(), b.GLGetY(), 0.0f,
							c.GLGetX(), c.GLGetY(), 0.0f};


	glUseProgram(Shaders::SIMPLE_SHADER);

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
