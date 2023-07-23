#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::SetupPerspective()
{
	glm::mat4 projection = glm::perspective(glm::radians(fov), (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);
	GLint projLoc = glGetUniformLocation(shaderID, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Application::SetupCamera()
{
	glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	GLint viewLoc = glGetUniformLocation(shaderID, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

void Application::SetupLighting()
{
	GLint viewPosLoc = glGetUniformLocation(shaderID, "viewPos");
	glUniform3f(viewPosLoc, cameraPos.x, cameraPos.y, cameraPos.z);
}

void Application::Init()
{	
	// Inisiasi shader.
	shaderID = BuildShader("vertexShader.vert",
		"fragmentShader.frag", nullptr);
	
	// Inisiasi komponen kubus pintu.
	door = Cube();
	doorKnob = Cube();
	door.Init("wooddoor.png", "wooddoor.png");
	doorKnob.Init("whiteplastic.png", "whiteplastic.png");

	// Inisiasi komponen kubus meja.
	table = Cube();
	table.Init("woodtable.png", "woodtable.png");

	// Inisiasi komponen kubus kursi.
	chair = Cube();
	chair.Init("woodchair.png", "woodchair.png");

	// Inisiasi komponen kubus proyektor.
	projectorBody = Cube();
	projectorLens = Cube();
	projectorSupport = Cube();
	projectorBody.Init("whiteplastic.png", "whiteplastic.png");
	projectorLens.Init("lensaproyektor.png", "lensaproyektor.png");
	projectorSupport.Init("blackmetal.png", "blackmetal.png");

	// Inisiasi komponen kubus jendela.
	windowFrame = Cube();
	windowGlass = Cube();
	windowFrame.Init("framewindow.png", "framewindow.png");
	windowGlass.Init("glass.png", "glass.png");

	// Inisiasi komponen kubus papan tulis.
	boardFrame = Cube();
	board = Cube();
	boardFrame.Init("frameboard.png", "frameboard.png");
	board.Init("whiteboard.png", "whiteboard.png");

	// Inisiasi komponen kubus lampu.
	lampBulb = Cube();
	lampSupport = Cube();
	lampBulb.Init("lamp.png", "lamp.png");
	lampSupport.Init("blackmetal.png", "blackmetal.png");

	// Inisiasi komponen plane atap.
	ceiling = Plane();
	ceiling.Init("ceiling.png");

	// Inisiasi komponen plane dinding.
	wall = Plane();
	wall.Init("wall.png");

	// Inisiasi komponen plane lantai.
	floor = Plane();
	floor.Init("floor.png");
}

void Application::DeInit()
{

}

void Application::Update(double deltaTime)
{
	lastLightToggled += deltaTime;
	ProcessInput(this->window);
}

// Rendering objek proyektor.
void Application::RenderProjectorObject(float offsetX, float offsetY, float offsetZ) {
	projectorSupport.Draw(shaderID, angle,
		0.2, 1, 0.2,
		offsetX + 0, offsetY + 0.5, offsetZ + 0);

	projectorBody.Draw(shaderID, angle,
		1, 0.35, 1,
		offsetX + 0, offsetY + 0, offsetZ + 0);

	projectorLens.Draw(shaderID, angle,
		0.25, 0.25, 0.25,
		offsetX + 0.2, offsetY + 0.1, offsetZ + 0.5);

	projectorSupport.Draw(shaderID, angle,
		0.1, 0.15, 0.1,
		offsetX + 0.4, offsetY + -0.2, offsetZ + -0.4);

	projectorSupport.Draw(shaderID, angle,
		0.1, 0.15, 0.1,
		offsetX + -0.4, offsetY + -0.2, offsetZ + -0.4);

	projectorSupport.Draw(shaderID, angle,
		0.1, 0.15, 0.1,
		offsetX + -0.4, offsetY + -0.2, offsetZ + 0.4);

	projectorSupport.Draw(shaderID, angle,
		0.1, 0.15, 0.1,
		offsetX + 0.4, offsetY + -0.2, offsetZ + 0.4);
}

// Rendering objek pintu.
void Application::RenderDoorObject(float offsetX, float offsetY, float offsetZ) {
	door.Draw(shaderID, angle,
		0.2625, 4.5, 1.75,
		offsetX + 0, offsetY + 0, offsetZ + 0);

	door.Draw(shaderID, angle,
		0.4375, 1.8125, 1.3125,
		offsetX + 0, offsetY - 1.1, offsetZ + 0);

	door.Draw(shaderID, angle,
		0.4375, 1.8125, 1.3125,
		offsetX + 0, offsetY + 1.1, offsetZ + 0);

	doorKnob.Draw(shaderID, angle,
		0.0875, 0.0875, 0.35,
		offsetX + 0.475, offsetY + 0.045, offsetZ - 0.4);

	doorKnob.Draw(shaderID, angle,
		0.35, 0.0875, 0.0875,
		offsetX + 0.35, offsetY + 0.045, offsetZ - 0.6);
}

// Rendering objek kursi.
void Application::RenderChairObject(float offsetX, float offsetY, float offsetZ) {
	chair.Draw(shaderID, angle,
		0.25, 1, 0.25, 
		offsetX + -0.4, offsetY + 0.1, offsetZ + -0.4); 
	chair.Draw(shaderID, angle,
		0.25, 1, 0.25, 
		offsetX + 0.4, offsetY + 0.1, offsetZ + -0.4); 
	chair.Draw(shaderID, angle,
		0.25, 1, 0.25, 
		offsetX + -0.4, offsetY + 0.1, offsetZ + 0.4); 
	chair.Draw(shaderID, angle,
		0.25, 1, 0.25, 
		offsetX + 0.4, offsetY + 0.1, offsetZ + 0.4); 
	
	chair.Draw(shaderID, angle,
		1.2, 0.18, 1.2, 
		offsetX + 0, offsetY + 0.65, offsetZ + 0); 

	chair.Draw(shaderID, angle,
		0.18, 1.1, 0.18, 
		offsetX + -0.4, offsetY + 1.25, offsetZ + -0.4); 
	chair.Draw(shaderID, angle,
		0.18, 1.1, 0.18, 
		offsetX + 0.4, offsetY + 1.25, offsetZ + -0.4); 
	
	chair.Draw(shaderID, angle,
		0.70, 0.18, 0.10, 
		offsetX + 0, offsetY + 1.3, offsetZ + -0.4); 
	chair.Draw(shaderID, angle,
		0.70, 0.18, 0.10, 
		offsetX + 0, offsetY + 1.6, offsetZ + -0.4);
}

// Rendering objek kursi guru (kursi yang dirotasi 180 derajat).
void Application::RenderTeacherChairObject(float offsetX, float offsetY, float offsetZ) {
	chair.Draw(shaderID, angle,
		0.25, 1, 0.25, 
		offsetX + -0.4, offsetY + 0.1, offsetZ + -0.4); 
	chair.Draw(shaderID, angle,
		0.25, 1, 0.25, 
		offsetX + 0.4, offsetY + 0.1, offsetZ + -0.4); 
	chair.Draw(shaderID, angle,
		0.25, 1, 0.25, 
		offsetX + -0.4, offsetY + 0.1, offsetZ + 0.4); 
	chair.Draw(shaderID, angle,
		0.25, 1, 0.25, 
		offsetX + 0.4, offsetY + 0.1, offsetZ + 0.4); 
	
	chair.Draw(shaderID, angle,
		1.2, 0.18, 1.2, 
		offsetX + 0, offsetY + 0.65, offsetZ + 0); 

	chair.Draw(shaderID, angle,
		0.18, 1.1, 0.18, 
		offsetX + -0.4, offsetY + 1.25, offsetZ + 0.4); 
	chair.Draw(shaderID, angle,
		0.18, 1.1, 0.18, 
		offsetX + 0.4, offsetY + 1.25, offsetZ + 0.4); 
	
	chair.Draw(shaderID, angle,
		0.70, 0.18, 0.10, 
		offsetX + 0, offsetY + 1.3, offsetZ + 0.4); 
	chair.Draw(shaderID, angle,
		0.70, 0.18, 0.10, 
		offsetX + 0, offsetY + 1.6, offsetZ + 0.4);
}

// Rendering objek meja.
void Application::RenderTableObject(float offsetX, float offsetY, float offsetZ) {
	table.Draw(shaderID, angle,
		4, 0.25, 2,
		offsetX + 0, offsetY + 0.85, offsetZ + 0);

	table.Draw(shaderID, angle,
		0.3, 1.8, 0.3, 
		offsetX + -1.75, offsetY + 0, offsetZ + -0.75); 
	table.Draw(shaderID, angle,
		0.3, 1.8, 0.3, 
		offsetX + 1.75, offsetY + 0, offsetZ + -0.75);
	table.Draw(shaderID, angle,
		0.3, 1.8, 0.3, 
		offsetX + -1.75, offsetY + 0, offsetZ + 0.75); 
	table.Draw(shaderID, angle,
		0.3, 1.8, 0.3, 
		offsetX + 1.75, offsetY + 0, offsetZ + 0.75); 
}

// Rendering objek papan tulis.
void Application::RenderBoardObject(float offsetX, float offsetY, float offsetZ) {
	
	board.Draw(shaderID, angle,
		5, 3, 0.15, 
		offsetX + 0, offsetY + 0.25, offsetZ + 0); 
	
	boardFrame.Draw(shaderID, angle,
		0.2, 3, 0.2, 
		offsetX + -2.6, offsetY + 0.25, offsetZ + 0);
	boardFrame.Draw(shaderID, angle,
		0.2, 3, 0.2, 
		offsetX + 2.6, offsetY + 0.25, offsetZ + 0);
	
	boardFrame.Draw(shaderID, angle,
		5.2, 0.2, 0.2, 
		offsetX + 0, offsetY + 1.77, offsetZ + 0); 
	
	boardFrame.Draw(shaderID, angle,
		5.2, 0.2, 0.5, 
		offsetX + 0, offsetY + -1.27, offsetZ - 0.3);
}

// Rendering objek 1 meja dan 2 kursi yang disatukan.
void Application::RenderChairTableSet(float offsetX, float offsetY, float offsetZ) {
	RenderTableObject(offsetX + 0, offsetY + 0.4, offsetZ + 0);
	RenderChairObject(offsetX + 0.8, offsetY - 0.1, offsetZ - 1.2);
	RenderChairObject(offsetX - 0.8, offsetY - 0.1, offsetZ - 1.2);
}

// Rendering objek jendela beserta 1 buah spot light.
void Application::RenderWindowObject(float offsetX, float offsetY, float offsetZ, int spotLightIndex, float isRight) {
	windowGlass.Draw(shaderID, angle,
		0.05, 0.6, 0.8,
		offsetX + 0, offsetY + 0.35, offsetZ - 0.45);
	windowGlass.Draw(shaderID, angle,
		0.05, 0.6, 0.8,
		offsetX + 0, offsetY - 0.35, offsetZ + 0.45);
	windowGlass.Draw(shaderID, angle,
		0.05, 0.6, 0.8,
		offsetX + 0, offsetY - 0.35, offsetZ - 0.45);
	windowGlass.Draw(shaderID, angle,
		0.05, 0.6, 0.8,
		offsetX + 0, offsetY + 0.35, offsetZ + 0.45);

	windowFrame.Draw(shaderID, angle,
		0.13, 1.6, 0.13,
		offsetX + 0, offsetY + 0, offsetZ + -0.8);
	windowFrame.Draw(shaderID, angle,
		0.13, 1.6, 0.13,
		offsetX + 0, offsetY + 0, offsetZ + 0);
	windowFrame.Draw(shaderID, angle,
		0.13, 1.6, 0.13,
		offsetX + 0, offsetY + 0, offsetZ + 0.8);

	windowFrame.Draw(shaderID, angle,
		0.13, 0.13, 1.5,
		offsetX + 0, offsetY + 0.735, offsetZ + 0);
	windowFrame.Draw(shaderID, angle,
		0.13, 0.13, 1.5,
		offsetX + 0, offsetY + 0, offsetZ + 0);
	windowFrame.Draw(shaderID, angle,
		0.13, 0.13, 1.5,
		offsetX + 0, offsetY + -0.735, offsetZ + 0);

	glUniform3fv(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].position")).c_str()),
		1, glm::value_ptr(glm::vec3(offsetX - (0.5 * isRight), offsetY, offsetZ)));
	glUniform3fv(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].direction")).c_str()),
		1, glm::value_ptr(glm::vec3((1 * isRight), 0, 0)));
	glUniform3f(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].ambient")).c_str()),
		0.98f, 0.84f, 0.65f);
	glUniform3f(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].diffuse")).c_str()),
		0.98f, 0.84f, 0.65f);
	glUniform3f(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].specular")).c_str()),
		0.98f, 0.84f, 0.65f);
	glUniform1f(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].constant")).c_str()),
		skyOn ? 1.5f : 1000);
	glUniform1f(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].linear")).c_str()),
		skyOn ? 0.25f : 1000);
	glUniform1f(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].quadratic")).c_str()),
		skyOn ? 0.15f : 1000);
	glUniform1f(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].cutOff")).c_str()),
		glm::cos(glm::radians(60.0f)));
	glUniform1f(glGetUniformLocation(shaderID,
		(std::string("spotLights[") + std::to_string(spotLightIndex) + std::string("].outerCutOff")).c_str()),
		glm::cos(glm::radians(80.0f)));
}

// Rendering objek lampu beserta 1 buah point light.
void Application::RenderLampObject(float offsetX, float offsetY, float offsetZ, int pointLightIndex) {
	lampBulb.Draw(shaderID, angle,
		0.2, 0.25, 0.2,
		offsetX + 0, offsetY + 0, offsetZ + 0);

	lampSupport.Draw(shaderID, angle,
		0.1, 0.25, 0.1,
		offsetX + 0, offsetY + 0.1, offsetZ + 0);

	glUniform3f(glGetUniformLocation(shaderID,
		(std::string("pointLights[") + std::to_string(pointLightIndex) + std::string("].position")).c_str()),
		offsetX + 0, offsetY + 0, offsetZ + 0);
	glUniform3f(glGetUniformLocation(shaderID,
		(std::string("pointLights[") + std::to_string(pointLightIndex) + std::string("].ambient")).c_str()),
		1.0f, 0.98f, 0.99f);
	glUniform3f(glGetUniformLocation(shaderID,
		(std::string("pointLights[") + std::to_string(pointLightIndex) + std::string("].diffuse")).c_str()),
		1.0f, 0.98f, 0.99f);
	glUniform3f(glGetUniformLocation(shaderID,
		(std::string("pointLights[") + std::to_string(pointLightIndex) + std::string("].specular")).c_str()),
		1.0f, 0.98f, 0.99f);
	glUniform1f(glGetUniformLocation(shaderID,
		(std::string("pointLights[") + std::to_string(pointLightIndex) + std::string("].constant")).c_str()),
		lampOn ? 1.0f : 1000);
	glUniform1f(glGetUniformLocation(shaderID,
		(std::string("pointLights[") + std::to_string(pointLightIndex) + std::string("].linear")).c_str()),
		lampOn ? 0.5f : 1000);
	glUniform1f(glGetUniformLocation(shaderID,
		(std::string("pointLights[") + std::to_string(pointLightIndex) + std::string("].quadratic")).c_str()),
		lampOn ? 0.1f : 1000);
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	SetupPerspective();
	SetupCamera();
	SetupLighting();

	// Penempatan objek-objek.
	RenderChairTableSet(-5, 0, -8);
	RenderChairTableSet(0, 0, -8);
	RenderChairTableSet(5, 0, -8);

	RenderChairTableSet(-5, 0, -4);
	RenderChairTableSet(0, 0, -4);
	RenderChairTableSet(5, 0, -4);

	RenderChairTableSet(-5, 0, 0);
	RenderChairTableSet(0, 0, 0);
	RenderChairTableSet(5, 0, 0);

	RenderChairTableSet(-5, 0, 4);
	RenderChairTableSet(0, 0, 4);
	RenderChairTableSet(5, 0, 4);

	RenderChairTableSet(-5, 0, 8);
	RenderChairTableSet(0, 0, 8);
	RenderChairTableSet(5, 0, 8);

	RenderTableObject(5, 0.4, 11);
	RenderTeacherChairObject(5, -0.1, 13);

	RenderBoardObject(0, 3, 14);

	RenderDoorObject(-10, 1.75, 12);

	RenderProjectorObject(0, 5, 0);

	RenderLampObject(-5, 5.8, -8, 0);
	RenderLampObject(-5, 5.8, 0, 1);
	RenderLampObject(-5, 5.8, 8, 2);
	RenderLampObject(5, 5.8, 0, 3);
	RenderLampObject(5, 5.8, 8,  4);
	RenderLampObject(5, 5.8, -8, 5);

	RenderWindowObject(-10, 3, 8, 0, 1);
	RenderWindowObject(-10, 3, 0, 1, 1);
	RenderWindowObject(-10, 3, -8, 2, 1);
	RenderWindowObject(10, 3, 8, 3, -1);
	RenderWindowObject(10, 3, 0, 4, -1);
	RenderWindowObject(10, 3, -8, 5, -1);

	// Penempatan plane dinding, atap, dan lantai.
	floor.Draw(shaderID, angle, glm::vec3(1, 0, 0), 0, 0, 0);
	ceiling.Draw(shaderID, angle, glm::vec3(1, 0, 0), 0, 6.5, 0);
	wall.Draw(shaderID, glm::half_pi<float>(), glm::vec3(1, 0, 0), 0, 0, 14.5);
	wall.Draw(shaderID, glm::half_pi<float>(), glm::vec3(0, 0, 1), -10.5, 0, 0);
	wall.Draw(shaderID, glm::half_pi<float>(), glm::vec3(1, 0, 0), 0, 0, -14.5);
	wall.Draw(shaderID, glm::half_pi<float>(), glm::vec3(0, 0, 1), 9.5, 0, 0);

	glDisable(GL_DEPTH_TEST);
}

void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	
	// Parsing posisi mouse untuk mengendalikan orientasi kamera.
	double xpos;
	double ypos;
	glfwGetCursorPos(this->window, &xpos, &ypos);
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xOffset = xpos - lastX;
	float yOffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	const float sensitivity = 0.1f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0f) pitch = 89.0f;
	if (pitch < -89.0f) pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);

	// Parsing tombol keyboard untuk mengatur kecepatan player.
	float cameraSpeed = 0.01f;
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		cameraSpeed *= 2;
	}

	// Parsing tombol keyboard untuk pergerakan player.
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		cameraPos.y += cameraSpeed;
		cameraFront.y += cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		cameraPos.y -= cameraSpeed;
		cameraFront.y -= cameraSpeed;
	}

	// Parsing tombol keyboard untuk toggle pencahayaan.
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && lastLightToggled > 200) {
		lampOn = !lampOn;
		lastLightToggled = 0;
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && lastLightToggled > 200) {
		skyOn = !skyOn;
		lastLightToggled = 0;
	}
}

int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Final Project Grafika Komputer SA 2023 - Kelompok SMAN FILKOM - Ruang Kelas SMA", 
		1280, 768, 
		false, 
		false);
}