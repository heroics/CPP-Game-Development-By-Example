#include <GL/glew.h>
#include <GLFW/glfw3.h>
//Function Prototype
void renderScene();
void initGame();
#include "Camera.h"
#include "LightRenderer.h"
#include "ShadeLoader.h"
#include <iostream>

// Instance Variables
Camera *camera;
LightRenderer *lightRenderer;

static void glfwError(int id, const char *description)
{
  std::cout << description << std::endl;
}

void renderScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0, 1.0, 0.0, 1.0);
  lightRenderer->draw();
}

void initGame()
{
  glEnable(GL_DEPTH_TEST);
  ShadeLoader shader;
  GLuint flatShaderProgram = shader.createProgram("Assets/Shaders/FlatModel.vs", "Assets/Shaders/FlatModel.fs");
  camera = new Camera(45.0f, 800, 600, 0.1f, 100.0f, glm::vec3(0.0f, 4.0f, 6.0f));
  lightRenderer = new LightRenderer(MeshType::CUBE, camera);
  lightRenderer->setProgram(flatShaderProgram);
  lightRenderer->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
}
int main(int argc, char **argv)
{
  glfwSetErrorCallback(&glfwError);
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  GLFWwindow *gameWindow = glfwCreateWindow(800, 600, "BEHOLD!", NULL, NULL);
  glfwMakeContextCurrent(gameWindow);
  glewInit();
  initGame();
  while (!glfwWindowShouldClose(gameWindow))
  {
    // Render our scene
    renderScene();
    glfwSwapBuffers(gameWindow);
    glfwPollEvents();
  }
  glfwTerminate();
  delete camera;
  delete lightRenderer;
  return 0;
}
