#pragma once
#include "MathEngine.h"

class Vector4 {
public:
    // Componentes del vector en 4D
    float x, y, z, w; // Coordenadas X, Y, Z, W

    /**
     * @brief Constructor por defecto
     * Inicializa las coordenadas del vector en 0.
     */
    Vector4() : x(0), y(0), z(0), w(0) {}

    /**
     * @brief Constructor parametrizado
     * Inicializa el vector con las coordenadas dadas.
     * @param x Coord X
     * @param y Coord Y
     * @param z Coord Z
     * @param w Coord W
     */
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    // Sobrecarga del operador de suma
    Vector4 operator+(const Vector4& other) const {
        return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    // Sobrecarga del operador de resta
    Vector4 operator-(const Vector4& other) const {
        return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    // Sobrecarga del operador de multiplicación por un escalar
    Vector4 operator*(float scalar) const {
        return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    /**
     * @brief Calcula la magnitud del vector
     * @return La magnitud del vector.
     */
    float magnitude() const {
        return MathEngine::sqrt(x * x + y * y + z * z + w * w);
    }

    /**
     * @brief Normaliza el vector
     * @return Un vector en la misma dirección con magnitud 1.
     * Si la magnitud es 0, se devuelve un vector (0, 0, 0, 0).
     */
    Vector4 normalize() const {
        float mag = magnitude();
        return (mag == 0) ? Vector4(0, 0, 0, 0) : Vector4(x / mag, y / mag, z / mag, w / mag);
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
