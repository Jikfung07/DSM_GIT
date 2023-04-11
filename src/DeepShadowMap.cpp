#include "../include/DeepShadowMap.h"

DeepShadowMap::DeepShadowMap(unsigned int width, unsigned int height)
    : width(width), height(height) {
    shadowMap.resize(width * height);
}

DeepShadowMap::~DeepShadowMap() {
}

void DeepShadowMap::Clear() {
    for (auto& pixelSamples : shadowMap) {
        pixelSamples.clear();
    }
}

void DeepShadowMap::InsertSample(float depth, const glm::vec3& color) {
    // à faire plus tard
    for (auto& pixelSamples : shadowMap) {
        pixelSamples.emplace_back(depth, color);
    }
}

glm::vec3 DeepShadowMap::QueryVisibility(float depth) const {
    // à faire plus tard
    glm::vec3 visibility(1.0f);
    for (const auto& sample : shadowMap[0]) {
        if (depth > sample.depth) {
            visibility *= sample.color;
        }
    }
    return visibility;
}
