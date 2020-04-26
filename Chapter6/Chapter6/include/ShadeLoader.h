#ifndef SHADELOADER_H
#define SHADELOADER_H
#include <GL/glew.h>
#include <string>
using namespace std;

class ShadeLoader
{
public:
    GLuint createProgram(const char *vertexShaderFilename, const char *fragmentShaderFilename);
    ShadeLoader();
    virtual ~ShadeLoader();

protected:
private:
    string readShader(const char *fileName);
    GLuint createShader(GLenum shaderType, string source, const char *shaderName);
};

#endif // SHADELOADER_H
