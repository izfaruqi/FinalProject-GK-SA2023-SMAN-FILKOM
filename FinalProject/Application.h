#pragma once

#include "RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>
#include "Cube.h"
#include "Plane.h"

class Application :
    public RenderEngine
{
public:
    Application();
    ~Application();
private:
	GLuint shaderID;

	Cube door;
	Cube doorKnob;
	Cube table;
	Cube chair;
	Cube projectorBody;
	Cube projectorLens;
	Cube projectorSupport;
	Cube windowFrame;
	Cube windowGlass;
	Cube boardFrame;
	Cube board;
	Cube lampBulb;
	Cube lampSupport;

	Plane ceiling;
	Plane wall;
	Plane floor;

	float angle = 0;
	void SetupPerspective();
	void SetupCamera();
	void SetupLighting();
	void RenderProjectorObject(float offsetX, float offsetY, float offsetZ);
	void RenderDoorObject(float offsetX, float offsetY, float offsetZ);
	void RenderLampObject(float offsetX, float offsetY, float offsetZ, int pointLightIndex);
	void RenderTableObject(float offsetX, float offsetY, float offsetZ);
	void RenderBoardObject(float offsetX, float offsetY, float offsetZ);
	void RenderChairObject(float offsetX, float offsetY, float offsetZ);
	void RenderTeacherChairObject(float offsetX, float offsetY, float offsetZ);
	void RenderWindowObject(float offsetX, float offsetY, float offsetZ, int spotLightIndex, float isRight);
	void RenderChairTableSet(float offsetX, float offsetY, float offsetZ);
	virtual void Init();
	virtual void DeInit(); 
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);

	const int windowWidth = 1280;
	const int windowHeight = 768;

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	float yaw = -90.0f;
	float pitch = 0.0f;
	float fov = 70.0f;

	bool firstMouse = true;
	float lastX = windowWidth / 2.0f;
	float lastY = windowHeight / 2.0f;

	bool lampOn = true;
	bool skyOn = true;
	double lastLightToggled = 0;
};

