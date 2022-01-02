//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
////������ʱ��仯��ɫ
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
//	//��������
//	float vertices[] = {
//		0.5f, 0.5f, 0.0f,   // ���Ͻ�
//		0.5f, -0.5f, 0.0f,  // ���½�
//		-0.5f, -0.5f, 0.0f, // ���½�
//		-0.5f, 0.5f, 0.0f   // ���Ͻ�
//	};
//
//	unsigned int indices[] = { // ע��������0��ʼ! 
//		0, 1, 3, // ��һ��������
//		1, 2, 3  // �ڶ���������
//	};
//
//
//	//���������������
//	unsigned int VAO;
//	glGenVertexArrays(1, &VAO);
//	//��VAO
//	glBindVertexArray(VAO);
//	//��������
//	unsigned int VBO;
//	glGenBuffers(1, &VBO);
//	//���������������
//	unsigned int EBO;
//	glGenBuffers(1, &EBO);
//
//	//���ƶ������鵽�����й�OpenGLʹ��
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	//��EBO
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//	//�������ݽ��� ,���ö�������ָ��
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//������ɫ��
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
//	//�жϳɹ�������������Ϣ
//	int  success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	//Ƭ����ɫ��
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
//	//������ɫ�����򣬽������ɫ���ϲ�
//	unsigned int shaderProgram;
//	shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	//�ж���ɫ������ɹ����
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//	}
//
//	//������ɫ������
//	glUseProgram(shaderProgram);
//
//
//	//ɾ����ɫ������
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//	//�����߿�ģʽ
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	//glBindVertexArray(VAO);
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		//��Ƭ����ɫ����ȫ�ֱ����趨ֵ
//		float timeValue = glfwGetTime();
//		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//		int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//		//�趨ȫ�ֱ���ֵ
//		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//
//
//		//��������
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
