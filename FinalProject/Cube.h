#pragma once

#include <glad/glad.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

class Cube
{
private:
	GLuint vbo, ebo, vao, textureID, sTextureID, shaderID;
	void InitData();
	void InitTexture(const char* diffPath, const char* specPath);
public:
	void Init(const char* diffPath, const char* specPath);
	void Draw(GLuint shaderID, float angle,
		float sx, float sy, float sz,
		float x, float y, float z);
};

