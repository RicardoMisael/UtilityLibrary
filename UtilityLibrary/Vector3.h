#pragma once
#include "MathEngine.h"

class Vector3 {
public:
    // Coordenadas del vector en 3D
    float x, y, z; // Componentes X, Y, Z

    /**
     * @brief Constructor por defecto
     * Inicializa las coordenadas del vector en 0.
     */
    Vector3() : x(0), y(0), z(0) {}

    /**
     * @brief Constructor parametrizado
     * Inicializa el vector con las coordenadas dadas.
     * @param x Coord X
     * @param y Coord Y
     * @param z Coord Z
     */
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Sobrecarga del operador de suma
    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    // Sobrecarga del operador de resta
    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    // Sobrecarga del operador de multiplicación por un escalar
    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    /**
     * @brief Calcula la magnitud del vector
     * @return La magnitud del vector.
     */
    float magnitude() const {
        return MathEngine::sqrt(x * x + y * y + z * z);
    }

    /**
     * @brief Normaliza el vector
     * @return Un vector en la misma dirección con magnitud 1.
     * Si la magnitud es 0, se devuelve un vector (0, 0, 0).
     */
    Vector3 normalize() const {
        float mag = magnitude();
        return (mag == 0) ? Vector3(0, 0, 0) : Vector3(x / mag, y / mag, z / mag);
    }

    // Devuelve un puntero a los datos no constantes
    float* data() {
        return &x; // Puntero a la coordenada X
    }

    // Devuelve un puntero a los datos constantes
    const float* data() const {
        return &x; // Puntero a la coordenada X
    }
};
