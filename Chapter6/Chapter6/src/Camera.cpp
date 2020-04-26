#include "Camera.h"
using namespace glm;
Camera::Camera(GLfloat fieldOfView, GLfloat widith, GLfloat height, GLfloat nearPlane, GLfloat farPlane, vec3 cameraPosition)
{
    this->cameraPosition = cameraPosition;
    vec3 cameraFront = vec3(0.0f, 0.0f, 0.0f);
    vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);
    this->viewMatrix = lookAt(cameraPosition, cameraFront, cameraUp);
    this->projectionMatrix = perspective(fieldOfView, widith / height, nearPlane, farPlane);
}
Camera::~Camera()
{
    //dtor
}
mat4 Camera::getProjectionMatrix()
{
    return this->projectionMatrix;
}
mat4 Camera::getViewMatrix()
{
    return this->viewMatrix;
}
vec3 Camera::getCameraPosition()
{
    return this->cameraPosition;
}
