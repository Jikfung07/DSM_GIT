#include "../include/Scene.h"

Scene::Scene()
    : camera(nullptr) {
}

Scene::~Scene() {
    for (auto& mesh : meshes) {
        delete mesh;
    }

    for (auto& light : lights) {
        delete light;
    }

    // Do not delete the camera, as it might be shared between multiple scenes
}

void Scene::AddMesh(Mesh* mesh) {
    meshes.push_back(mesh);
}

void Scene::AddLight(Light* light) {
    lights.push_back(light);
}

void Scene::SetCamera(Camera* camera) {
    this->camera = camera;
}

const std::vector<Mesh*>& Scene::GetMeshes() const {
    return meshes;
}

const std::vector<Light*>& Scene::GetLights() const {
    return lights;
}

const Camera* Scene::GetCamera() const {
    return camera;
}
