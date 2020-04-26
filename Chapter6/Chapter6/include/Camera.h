#ifndef CAMERA_H
#define CAMERA_H
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
class Camera
{
public:
    Camera(GLfloat fieldOfView, GLfloat widith, GLfloat height, GLfloat nearPlane, GLfloat farPlane, vec3 cameraPosition);
    virtual ~Camera();
    mat4 getViewMatrix();
    mat4 getProjectionMatrix();
    vec3 getCameraPosition();
protected:
private:
    mat4 viewMatrix;
    mat4 projectionMatrix;
    vec3 cameraPosition;
};
#endif // CAMERA_H
