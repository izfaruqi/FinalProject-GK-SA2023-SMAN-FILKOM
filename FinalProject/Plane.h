#pragma once

#include <glad/glad.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

class Plane
{
private:
	GLuint shaderProgram, VBO, VAO, EBO, texture, VBO2, VAO2, EBO2;
	void InitData(const char* diffPath);
	void InitTexture(const char* diffPath);
public:
	void Init(const char* diffPath);
	void Draw(GLuint shaderID, float angle,
		glm::vec3 angleAxis,
		float x, float y, float z);
};

