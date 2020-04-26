#include "LightRenderer.h"

LightRenderer::LightRenderer(MeshType meshType, Camera *camera)
{
    this->camera = camera;
    switch (meshType)
    {
    case TRIANGLE:
        Mesh::setTriangleData(vertices, indices);
        break;
    case QUAD:
        Mesh::setQuadData(vertices, indices);
        break;
    case CUBE:
        Mesh::setCubeData(vertices, indices);
        break;
    case SPHERE:
        Mesh::setSphereData(vertices, indices);
        break;

    default:
        break;
    }
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);
    glGenBuffers(1, &vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexArrayObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, Vertex::color)));
    glGenBuffers(1, &elementBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void LightRenderer::draw()
{
    glm::mat4 model = glm::mat4(1.0f);
    glUseProgram(this->program);
    GLint modelLocation = glGetUniformLocation(program, "model");
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
    glm::mat4 view = camera->getViewMatrix();
    GLint viewLocation = glGetUniformLocation(program, "view");
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
    glm::mat4 projectionMatrix = camera->getProjectionMatrix();
    GLint projectionLocation = glGetUniformLocation(program, "projection");
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glBindVertexArray(vertexArrayObject);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glUseProgram(0);
}
LightRenderer::~LightRenderer()
{
    //dtor
}
void LightRenderer::setPosition(glm::vec3 position)
{
    this->position = position;
}

void LightRenderer::setColor(glm::vec3 color)
{

    this->color = color;
}

void LightRenderer::setProgram(GLuint program)
{

    this->program = program;
}

//getters
glm::vec3 LightRenderer::getPosition()
{

    return this->position;
}

glm::vec3 LightRenderer::getColor()
{

    return this->color;
}