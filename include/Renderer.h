#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "Mesh.h"
#include "Camera.h"
#include "Light.h"
#include "Shader.h"

class Renderer {
public:
    Renderer(GLuint width, GLuint height);
    ~Renderer();

    void RenderScene(const Camera& camera, const std::vector<Mesh*>& meshes, const std::vector<Light*>& lights);
    void UpdateViewport(GLuint width, GLuint height);

private:
    GLuint screenWidth;
    GLuint screenHeight;

    Shader shadowShader;
    Shader deepShadowShader;
    Shader sceneShader;

    GLuint shadowMapFBO;
    GLuint shadowMapTexture;
    GLuint deepShadowMapFBO;
    GLuint deepShadowMapTexture;

    const GLuint shadowMapSize = 2048;


    // Add any necessary private methods or members here
};
