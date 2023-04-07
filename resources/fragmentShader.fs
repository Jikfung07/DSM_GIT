#version 330 core

struct Material {
    sampler2D diffuse;
    float shininess;
};

struct Light {
    vec3 position;
    vec3 color;
    float intensity;
};

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;
in vec3 LightDir;

uniform Material material;
uniform Light light;

out vec4 color;

void main() {
    // Ambient
    vec3 ambient = 0.1 * light.color;

    // Diffuse
    vec4 texColor = texture(material.diffuse, TexCoords);
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightDir);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * light.color * texColor.rgb;

    // Specular
    vec3 viewDir = normalize(-FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = spec * light.color;

    vec3 result = (ambient + diffuse + specular) * light.intensity;
    color = vec4(result, texColor.a);
}
