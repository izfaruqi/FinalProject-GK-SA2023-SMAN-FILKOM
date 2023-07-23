#include "Cube.h"

void Cube::InitData()
{
	// Inisiasi data vertex dan triangle.
	float vertices[] = {
		
		-0.5, -0.5, 0.5,   0, 0,  0.0f,  0.0f,  1.0f, 
		 0.5, -0.5, 0.5,   1, 0,  0.0f,  0.0f,  1.0f, 
		 0.5,  0.5, 0.5,   1, 1,  0.0f,  0.0f,  1.0f, 
		-0.5,  0.5, 0.5,   0, 1,  0.0f,  0.0f,  1.0f, 
		
		0.5,  0.5,  0.5,   0, 0,  1.0f,  0.0f,  0.0f, 
		0.5,  0.5, -0.5,   1, 0,  1.0f,  0.0f,  0.0f, 
		0.5, -0.5, -0.5,   1, 1,  1.0f,  0.0f,  0.0f, 
		0.5, -0.5,  0.5,   0, 1,  1.0f,  0.0f,  0.0f, 
		
		-0.5,  -0.5, -0.5, 0, 0,  0.0f,  0.0f,  -1.0f, 
		 0.5,  -0.5, -0.5, 1, 0,  0.0f,  0.0f,  -1.0f, 
		 0.5,   0.5, -0.5, 1, 1,  0.0f,  0.0f,  -1.0f, 
		-0.5,   0.5, -0.5, 0, 1,  0.0f,  0.0f,  -1.0f, 
		
		-0.5, -0.5, -0.5,  0, 0, -1.0f,  0.0f,  0.0f, 
		-0.5, -0.5,  0.5,  1, 0, -1.0f,  0.0f,  0.0f, 
		-0.5,  0.5,  0.5,  1, 1, -1.0f,  0.0f,  0.0f, 
		-0.5,  0.5, -0.5,  0, 1, -1.0f,  0.0f,  0.0f, 
		
		 0.5, 0.5,  0.5,   0, 0,   0.0f,  1.0f,  0.0f, 
		-0.5, 0.5,  0.5,   1, 0,   0.0f,  1.0f,  0.0f, 
		-0.5, 0.5, -0.5,   1, 1,   0.0f,  1.0f,  0.0f, 
		 0.5, 0.5, -0.5,   0, 1,   0.0f,  1.0f,  0.0f, 
		
		-0.5, -0.5, -0.5,  0, 0,   0.0f,  -1.0f,  0.0f, 
		 0.5, -0.5, -0.5,  1, 0,   0.0f,  -1.0f,  0.0f, 
		 0.5, -0.5,  0.5,  1, 1,   0.0f,  -1.0f,  0.0f, 
		-0.5, -0.5,  0.5,  0, 1,   0.0f,  -1.0f,  0.0f, 
	};

	unsigned int indices[] = {
		0,  1,  2,   0,  2,  3,   
		4,  5,  6,   4,  6,  7,   
		8,  9,  10,  8,  10, 11,  
		12, 14, 13,  12, 15, 14,  
		16, 18, 17,  16, 19, 18,  
		20, 22, 21,  20, 23, 22   
	};
	
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Cube::InitTexture(const char* diffPath, const char* specPath)
{
	// Inisiasi texture diffuse.
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image(diffPath, 
		&width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Inisiasi texture specular.
	glGenTextures(1, &sTextureID);
	glBindTexture(GL_TEXTURE_2D, sTextureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	image = SOIL_load_image(specPath, & width, & height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Cube::Init(const char* diffPath, const char* specPath)
{
	InitData();
	InitTexture(diffPath, specPath);
}

void Cube::Draw(GLuint shaderID, float angle,
	float sx, float sy, float sz,
	float x, float y, float z)
{
	glUseProgram(shaderID);

	// Pemasangan texture diffuse.
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glUniform1i(glGetUniformLocation(shaderID, "material.diffuse"), 0);

	// Pemasangan texture specular.
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, sTextureID);
	glUniform1i(glGetUniformLocation(shaderID, "material.specular"), 1);

	// Pemasangan nilai shininess.
	GLint shininessMatLoc = glGetUniformLocation(shaderID, "material.shininess");
	glUniform1f(shininessMatLoc, 5.0f);

	glBindVertexArray(vao); 

	// Proses kalkulasi translate, rotate, dan scale pada objek.
	// Scale dilakukan di paling akhir agar tidak merusak skala translasi dan rotasi 
	// (objek akan bergeser dengan jarak yang sama pada tingkat scale apapun).
	glm::mat4 model;
	model = glm::translate(glm::vec3(x, y, z));
	model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3(sx, sy, sz));

	GLint modelLoc = glGetUniformLocation(shaderID, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}
