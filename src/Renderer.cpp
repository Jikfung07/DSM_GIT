#include "../include/Renderer.h"

Renderer::Renderer(GLuint width, GLuint height)
    : screenWidth(width), screenHeight(height),
      shadowShader("path/to/shadowVertex.glsl", "path/to/shadowFragment.glsl"),
      deepShadowShader("path/to/deepShadowVertex.glsl", "path/to/deepShadowFragment.glsl"),
      sceneShader("path/to/sceneVertex.glsl", "path/to/sceneFragment.glsl") {

    // Create shadow map FBO and texture
    glGenFramebuffers(1, &shadowMapFBO);
    glGenTextures(1, &shadowMapTexture);
    glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapSize, shadowMapSize, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    GLfloat borderColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMapTexture, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // deep shadow map FBO and texture
    // à faire
}


Renderer::~Renderer() {}

void Renderer::RenderScene(const Camera& camera, const std::vector<Mesh*>& meshes, const std::vector<Light*>& lights) {
    // Render shadow maps
    glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
    glViewport(0, 0, shadowMapSize, shadowMapSize);
    glClear(GL_DEPTH_BUFFER_BIT);

    // Set up light space matrix
    glm::mat4 lightProjection, lightView, lightSpaceMatrix;
    GLfloat near_plane = 1.0f, far_plane = 7.5f;
    lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    lightView = glm::lookAt(lights[0]->getPosition(), glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));
    lightSpaceMatrix = lightProjection * lightView;

    shadowShader.Use();
    glUniformMatrix4fv(glGetUniformLocation(shadowShader.GetProgramID(), "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));

    for (const auto& mesh : meshes) {
        mesh->Draw(shadowShader.GetProgramID());
    }

    // Render deep shadow maps
    // ...
    // Similar to shadow maps, but you might need to update the light space matrix
    // and use a different shader program (deepShadowShader).

    // Reset viewport and bind default framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, screenWidth, screenHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render scene
    // ...

    // Pass shadow map and deep shadow map to the shader
    sceneShader.Use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
    glUniform1i(glGetUniformLocation(sceneShader.GetProgramID(), "shadowMap"), 0);
    
    // Pass deep shadow map
    // ...
}


void Renderer::UpdateViewport(GLuint width, GLuint height) {
    screenWidth = width;
    screenHeight = height;
    glViewport(0, 0, screenWidth, screenHeight);
}
