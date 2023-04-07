#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);
    ~Shader();

    GLuint GetProgramID() const;
    void Use();
    void SetFloat(const std::string &name, GLfloat value) const;
    void SetInt(const std::string &name, GLint value) const;
    void SetVec3(const std::string &name, const glm::vec3 &value) const;
    void SetVec4(const std::string &name, const glm::vec4 &value) const;
    void SetMat4(const std::string &name, const glm::mat4 &value) const;

private:
    GLuint programID;

    GLuint LoadShader(const std::string &path, GLenum shaderType);
    void CheckCompileErrors(GLuint shader, const std::string &type);
};
