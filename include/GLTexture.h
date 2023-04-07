#pragma once

#include <string>
#include <GL/glew.h>

class GLTexture {
public:
    GLTexture(const std::string &file_path);
    ~GLTexture();

    void Bind(GLuint unit) const;
    void Unbind() const;
    GLuint GetTextureID();

private:
    GLuint texture_id_;
};
