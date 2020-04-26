#ifndef MESH_H
#define MESH_H
#include "Mesh.h"
#include <glm/glm.hpp>
#include <vector>
using namespace glm;
using namespace std;
enum MeshType
{
    TRIANGLE,
    QUAD,
    CUBE,
    SPHERE
};
struct Vertex
{
    vec3 position;
    vec3 normal;
    vec3 color;
    vec2 textureCoordinates;
};

class Mesh
{
public:
    static void setTriangleData(vector<Vertex> &vertices, vector<uint32_t> &indices);
    static void setQuadData(vector<Vertex> &vertices, vector<uint32_t> &indices);
    static void setCubeData(vector<Vertex> &vertices, vector<uint32_t> &indices);
    static void setSphereData(vector<Vertex> &vertices, vector<uint32_t> &indices);

    Mesh();
    virtual ~Mesh();

protected:
private:
};

#endif // MESH_H
