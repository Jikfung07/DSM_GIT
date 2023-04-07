#include "../include/Light.h"

Light::Light(const glm::vec3 &position, const glm::vec3 &color, GLfloat intensity)
    : position(position), color(color), intensity(intensity) {}

glm::vec3 Light::getPosition() const {
        return position;
}

const glm::vec3 &Light::getColor() const {
    return color;
}

GLfloat Light::getIntensity() const {
    return intensity;
}

void Light::setPosition(const glm::vec3& newPosition) {
        position = newPosition;
}

void Light::setColor(const glm::vec3 &color) {
    this->color = color;
}

void Light::setIntensity(GLfloat intensity) {
    this->intensity = intensity;
}

// PointLight::PointLight(const glm::vec3 &color, GLfloat intensity, const glm::vec3 &position)
//     : Light(position, color, intensity) {}

// const glm::vec3 &PointLight::getPosition() const {
//     return position;
// }

// void PointLight::setPosition(const glm::vec3 &position) {
//     this->position = position;
// }
