#include "ShadeLoader.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ShadeLoader::ShadeLoader()
{
    //ctor
}

ShadeLoader::~ShadeLoader()
{
    //dtor
}
string ShadeLoader::readShader(const char *fileName)
{
    string shaderCode;
    std::ifstream file(fileName, std::ios::in);
    if (!file.good())
    {
        cout << "[ERROR] - Can not read file! " << fileName << endl;
        terminate();
    }
    file.seekg(0, std::ios::end);
    shaderCode.resize((unsigned int)file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&shaderCode[0], shaderCode.size());
    file.close();
    return shaderCode;
}
GLuint ShadeLoader::createShader(GLenum shaderType, std::string source, const char *shaderName)
{
    int compileResult = 0;
    GLuint shader = glCreateShader(shaderType);
    const char *SHADERCODEPTR = source.c_str();
    const int SHADERCODESIZE = source.size();
    glShaderSource(shader, 1, &SHADERCODEPTR, &SHADERCODESIZE);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);
    // Check for errors
    if (compileResult == GL_FALSE)
    {
        int infoLogLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        vector<char> shaderLog(infoLogLength);
        glGetShaderInfoLog(shader, infoLogLength, NULL, &shaderLog[0]);
        cout << "[ERROR] - Compiling shader: " << shaderName << endl
             << &shaderLog[0] << endl;
        return 0;
    }
    return shader;
}
GLuint ShadeLoader::createProgram(const char *vertexShaderFilename, const char *fragmentShaderFilename)
{
    string vertexShaderCode = readShader(vertexShaderFilename);
    string fragmentShaderCode = readShader(fragmentShaderFilename);
    GLuint vertexShader = createShader(GL_VERTEX_SHADER, vertexShaderCode, "vertex shader");
    GLuint fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentShaderCode, "fragment shader");
    int linkResult = 0;
    // Create the program handle, attach the shaders and link it
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &linkResult);
    if (linkResult == GL_FALSE)
    {
        int infoLogLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
        vector<char> programLog(infoLogLength);
        glGetProgramInfoLog(program, infoLogLength, NULL, &programLog[0]);
        cout << "[ERROR] - Shader Loader : LINK ERROR" << endl
             << &programLog[0] << endl;
        return 0;
    }
    return program;
}