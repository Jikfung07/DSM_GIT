#pragma once

#include <vector>
#include "Mesh.h"
#include "Camera.h"
#include "Light.h"

class Scene {
public:
    Scene();
    ~Scene();

    void AddMesh(Mesh* mesh);
    void AddLight(Light* light);
    void SetCamera(Camera* camera);

    const std::vector<Mesh*>& GetMeshes() const;
    const std::vector<Light*>& GetLights() const;
    const Camera* GetCamera() const;

private:
    std::vector<Mesh*> meshes;
    std::vector<Light*> lights;
    Camera* camera;
};
