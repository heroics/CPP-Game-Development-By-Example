#include "Mesh.h"
using namespace std;
void Mesh::setTriangleData(vector<Vertex> &vertices, vector<uint32_t> &indices)
{
    vector<Vertex> localVertices =
        {{{0.0f, -1.0f, 0.0f},
          {0.0f, 0.0f, 1.0f},
          {0.0f, 1.0f, 0.0f},
          {0.0f, 1.0f}},
         {{1.0f, 1.0f, 0.0f},
          {0.0f, 0.0f, 1.0f},
          {0.0f, 1.0f, 0.0f},
          {0.0f, 0.0f}},
         {{-1.0f, 1.0f, 0.0f},
          {0.0f, 0.0f, 1.0f},
          {0.0f, 0.0f, 1.0f},
          {1.0f, 0.0f}}};
    vector<uint32_t> localIndices = {0, 1, 2};
    vertices.clear();
    indices.clear();
    vertices = localVertices;
    indices = localIndices;
}
void Mesh::setQuadData(vector<Vertex> &vertices, vector<uint32_t> &indices)
{

    std::vector<Vertex> localVertices = {
        {{-1.0f, -1.0f, 0.0f},
         {0.0f, 0.0f, 1.0f},
         {1.0f, 0.0f, 0.0f},
         {0.0f, 1.0f}},
        {{-1.0f, 1.0f, 0.0f},
         {0.0f, 0.0f, 1.0f},
         {0.0f, 1.0f, 0.0f},
         {0.0f, 0.0f}},
        {{1.0f, 1.0f, 0.0f},
         {0.0f, 0.0f, 1.0f},
         {0.0f, 0.0f, 1.0f},
         {1.0f, 0.0f}},
        {{1.0f, -1.0f, 0.0f},
         {0.0f, 0.0f, 1.0f},
         {1.0f, 0.0f, 1.0f},
         {1.0f, 1.0f}}};
    std::vector<uint32_t> localIndices = {0, 1, 2, 0, 2, 3};
    vertices.clear();
    indices.clear();
    vertices = localVertices;
    indices = localIndices;
}

void Mesh::setCubeData(std::vector<Vertex> &vertices, std::vector<uint32_t> &indices)
{

    std::vector<Vertex> _vertices = {
        {{-1.0f, -1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f}},
        {{-1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}},
        {{1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
        {{1.0f, -1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
        {{1.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {1.0f, 0.0f}},
        {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {1.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{-1.0f, -1.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
        {{-1.0f, 1.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f, 1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
        {{-1.0f, -1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
        {{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
        {{1.0f, 1.0f, -1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
        {{1.0f, -1.0f, -1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
        {{-1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
        {{1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
        {{1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{-1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}},
        {{-1.0f, -1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}},
        {{1.0f, -1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
        {{1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}}};

    std::vector<uint32_t> _indices = {
        0, 1, 2,
        2, 3, 0,
        4, 5, 6,
        4, 6, 7,
        8, 9, 10,
        8, 10, 11,
        12, 13, 14,
        12, 14, 15,
        16, 17, 18,
        16, 18, 19,
        20, 21, 22,
        20, 22, 23};

    vertices.clear();
    indices.clear();
    vertices = _vertices;
    indices = _indices;
}
void Mesh::setSphereData(std::vector<Vertex> &vertices, std::vector<uint32_t> &indices)
{
    std::vector<Vertex> _vertices;
    std::vector<uint32_t> _indices;
    float latitudeBands = 20.0f;
    float longitudeBands = 20.0f;
    float radius = 1.0f;
    for (float latNumber = 0; latNumber <= latitudeBands; latNumber++)
    {
        float theta = latNumber * 3.14 / latitudeBands;
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);
        for (float longNumber = 0; longNumber <= longitudeBands; longNumber++)
        {
            float phi = longNumber * 2 * 3.147 / longitudeBands;
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);
            Vertex vs;
            vs.textureCoordinates.x = (longNumber / longitudeBands);
            vs.textureCoordinates.y = (latNumber / latitudeBands);
            vs.normal.x = cosPhi * sinTheta;
            vs.normal.y = cosTheta;
            vs.normal.z = sinPhi * sinTheta;
            vs.color.r = vs.normal.x;
            vs.color.g = vs.normal.y;
            vs.color.b = vs.normal.z;
            vs.position.x = radius * vs.normal.x;
            vs.position.y = radius * vs.normal.y;
            vs.position.z = radius * vs.normal.z;
            _vertices.push_back(vs);
        }
    }
    for (uint32_t latNumber = 0; latNumber < latitudeBands; latNumber++)
    {
        for (uint32_t longNumber = 0; longNumber < longitudeBands; longNumber++)
        {
            uint32_t first = (latNumber * (longitudeBands + 1)) + longNumber;
            uint32_t second = first + longitudeBands + 1;
            _indices.push_back(first);
            _indices.push_back(second);
            _indices.push_back(first + 1);
            _indices.push_back(second);
            _indices.push_back(second + 1);
            _indices.push_back(first + 1);
        }
    }
    vertices.clear();
    indices.clear();
    vertices = _vertices;
    indices = _indices;
}