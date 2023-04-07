#pragma once

#include <vector>
#include "glm/glm.hpp"

class DeepShadowMap {
public:
    DeepShadowMap(unsigned int width, unsigned int height);
    ~DeepShadowMap();

    void Clear();
    void InsertSample(float depth, const glm::vec3& color);
    glm::vec3 QueryVisibility(float depth) const;

private:
    struct Sample {
        float depth;
        glm::vec3 color;

        Sample(float depth, const glm::vec3& color) : depth(depth), color(color) {}
    };

    unsigned int width;
    unsigned int height;
    std::vector<std::vector<Sample>> shadowMap;
};

class VisibilityFunction {
public:
    std::vector<std::pair<float, float>> zvPairs; // 表示 z 和 V 值的数组

    // 构造函数和析构函数
    VisibilityFunction() {}
    ~VisibilityFunction() {}

    // 添加和删除点、线性插值等基本操作
};
