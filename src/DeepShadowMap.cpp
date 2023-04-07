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
    // This is a simplified version of the insertion, in practice, you may want to sort
    // the samples by depth and use a more sophisticated approach like the one described
    // in the paper to maintain the compressed representation.
    for (auto& pixelSamples : shadowMap) {
        pixelSamples.emplace_back(depth, color);
    }
}

glm::vec3 DeepShadowMap::QueryVisibility(float depth) const {
    // This is a simplified version of the visibility query, in practice, you may want
    // to interpolate between samples and apply a more sophisticated reconstruction
    // of the transmittance function as described in the paper.
    glm::vec3 visibility(1.0f);
    for (const auto& sample : shadowMap[0]) {
        if (depth > sample.depth) {
            visibility *= sample.color;
        }
    }
    return visibility;
}
