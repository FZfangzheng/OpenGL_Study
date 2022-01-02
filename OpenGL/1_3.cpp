//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
////绘制随时间变化颜色
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	glViewport(0, 0, 800, 600);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	//顶点数据
//	float vertices[] = {
//		0.5f, 0.5f, 0.0f,   // 右上角
//		0.5f, -0.5f, 0.0f,  // 右下角
//		-0.5f, -0.5f, 0.0f, // 左下角
//		-0.5f, 0.5f, 0.0f   // 左上角
//	};
//
//	unsigned int indices[] = { // 注意索引从0开始! 
//		0, 1, 3, // 第一个三角形
//		1, 2, 3  // 第二个三角形
//	};
//
//
//	//创建顶点数组对象
//	unsigned int VAO;
//	glGenVertexArrays(1, &VAO);
//	//绑定VAO
//	glBindVertexArray(VAO);
//	//顶点数据
//	unsigned int VBO;
//	glGenBuffers(1, &VBO);
//	//创建索引缓冲对象
//	unsigned int EBO;
//	glGenBuffers(1, &EBO);
//
//	//复制顶点数组到缓冲中供OpenGL使用
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//绑定EBO
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	//顶点数据解析 ,设置顶点属性指针
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//顶点着色器
//	const char *vertexShaderSource = "#version 330 core\n"
//		"layout (location = 0) in vec3 aPos;\n"
//		"void main()\n"
//		"{\n"
//		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//		"}\0";
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	//判断成功与否，输出报错信息
//	int  success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	//片段着色器
//	const char *fragmentShaderSource = "#version 330 core\n"
//		"out vec4 FragColor;\n"
//		"uniform vec4 ourColor;\n"
//		"void main()\n"
//		"{\n"
//		"   FragColor = ourColor;\n"
//		"}\0";
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	//创建着色器程序，将多个着色器合并
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	//判断着色器程序成功与否
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//	}
//
//	//调用着色器程序
//	glUseProgram(shaderProgram);
//
//
//	//删除着色器对象
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//	//设置线框模式
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	//glBindVertexArray(VAO);
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		//给片段着色器的全局变量设定值
//		float timeValue = glfwGetTime();
//		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//		int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//设定全局变量值
//		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//
//
//		//绘制物体
//		glBindVertexArray(VAO);
//		
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		//glBindVertexArray(0);
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	glfwTerminate();
//	return 0;
//}
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//void processInput(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
