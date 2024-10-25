#include <iostream>
#include "MathEngine.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"

int main() {
    // Ejemplo de uso de Vector2
    Vector2 vec2a(3.0f, 4.0f);
    Vector2 vec2b(1.0f, 2.0f);
    Vector2 vec2c = vec2a + vec2b;

    std::cout << "Vector2 A: (" << vec2a.x << ", " << vec2a.y << ")\n";
    std::cout << "Vector2 B: (" << vec2b.x << ", " << vec2b.y << ")\n";
    std::cout << "Vector2 C (A + B): (" << vec2c.x << ", " << vec2c.y << ")\n";
    std::cout << "Magnitude of C: " << vec2c.magnitude() << "\n";

    // Ejemplo de uso de Vector3
    Vector3 vec3a(1.0f, 2.0f, 3.0f);
    Vector3 vec3b(4.0f, 5.0f, 6.0f);
    Vector3 vec3c = vec3a + vec3b;

    std::cout << "Vector3 A: (" << vec3a.x << ", " << vec3a.y << ", " << vec3a.z << ")\n";
    std::cout << "Vector3 B: (" << vec3b.x << ", " << vec3b.y << ", " << vec3b.z << ")\n";
    std::cout << "Vector3 C (A + B): (" << vec3c.x << ", " << vec3c.y << ", " << vec3c.z << ")\n";
    std::cout << "Magnitude of C: " << vec3c.magnitude() << "\n";

    // Ejemplo de uso de Vector4
    Vector4 vec4a(1.0f, 2.0f, 3.0f, 4.0f);
    Vector4 vec4b(5.0f, 6.0f, 7.0f, 8.0f);
    Vector4 vec4c = vec4a + vec4b;

    std::cout << "Vector4 A: (" << vec4a.x << ", " << vec4a.y << ", " << vec4a.z << ", " << vec4a.w << ")\n";
    std::cout << "Vector4 B: (" << vec4b.x << ", " << vec4b.y << ", " << vec4b.z << ", " << vec4b.w << ")\n";
    std::cout << "Vector4 C (A + B): (" << vec4c.x << ", " << vec4c.y << ", " << vec4c.z << ", " << vec4c.w << ")\n";
    std::cout << "Magnitude of C: " << vec4c.magnitude() << "\n";

    // Ejemplo de uso de Quaternion
    Vector3 rotationAxis(0.0f, 1.0f, 0.0f); // Eje de rotación Y
    Quaternion quat1(MathEngine::PI / 4.0f, rotationAxis); // 45 grados de rotación

    std::cout << "Quaternion (W, X, Y, Z): ("
        << quat1.w << ", " << quat1.x << ", "
        << quat1.y << ", " << quat1.z << ")\n";

    // Rotar un vector utilizando el cuaternión
    Vector3 vecToRotate(1.0f, 0.0f, 0.0f);
    Vector3 rotatedVec = quat1.rotate(vecToRotate);

    std::cout << "Rotated Vector: ("
        << rotatedVec.x << ", " << rotatedVec.y << ", "
        << rotatedVec.z << ")\n";

    return 0;
}
