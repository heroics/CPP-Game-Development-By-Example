#ifndef LIGHTRENDERER_H
#define LIGHTRENDERER_H
#include "Camera.h"
#include "Mesh.h"
#include "ShadeLoader.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
using namespace glm;
class LightRenderer
{
public:
    LightRenderer(MeshType meshType, Camera *camera);
    void draw();
    void setColor(vec3 color);
    void setProgram(GLuint program);
    void setPosition(vec3 position);
    vec3 getPosition();
    vec3 getColor();
    virtual ~LightRenderer();

protected:
private:
    Camera *camera;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    glm::vec3 position;
    glm::vec3 color;
    GLuint vertexBufferObject;  // This is the geometrical information - position, color, normal, and texture Coordinates
    GLuint elementBufferObject; // This is used to store the index of each vertex
    GLuint vertexArrayObject;   // This is a helper container object that sores all the vertexBufferObjects and attributes
    GLuint program;
};
#endif // LIGHTRENDERER_H
