#pragma once

#include <GL/gl.h>
#include <glm/glm.hpp>

class Light {
public:
    Light(const glm::vec3 &position, const glm::vec3 &color, GLfloat intensity);

    glm::vec3 getPosition() const;
    const glm::vec3 &getColor() const;
    GLfloat getIntensity() const;

    void setPosition(const glm::vec3 &newPosition);
    void setColor(const glm::vec3 &color);
    void setIntensity(GLfloat intensity);

protected:
    glm::vec3 position;
    glm::vec3 color;
    GLfloat intensity;
};

// class PointLight : public Light {
// public:
//     PointLight(const glm::vec3 &color, GLfloat intensity, const glm::vec3 &position);

//     const glm::vec3 &getPosition() const;
//     void setPosition(const glm::vec3 &position);

// private:
//     glm::vec3 position;
// };
