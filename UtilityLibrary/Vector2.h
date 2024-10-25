#pragma once
#include "MathEngine.h"

class Vector2 {
public:
    // Coordenadas del vector
    float x; // Componente X
    float y; // Componente Y

    /**
     * @brief Constructor por defecto
     * Inicializa las coordenadas del vector en 0.
     */
    Vector2() : x(0), y(0) {}

    /**
     * @brief Constructor parametrizado
     * Inicializa el vector con las coordenadas dadas.
     * @param xVal Valor para la coordenada X.
     * @param yVal Valor para la coordenada Y.
     */
    Vector2(float xVal, float yVal) : x(xVal), y(yVal) {}

    // Sobrecarga del operador de suma
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // Sobrecarga del operador de resta
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    // Sobrecarga del operador de multiplicación por un escalar
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    /**
     * @brief Calcula la magnitud del vector
     * @return La magnitud del vector.
     */
    float magnitude() const {
        return MathEngine::sqrt(x * x + y * y);
    }

    /**
     * @brief Normaliza el vector
     * @return Un vector en la misma dirección con magnitud 1.
     * Si la magnitud es 0, se devuelve un vector (0, 0).
     */
    Vector2 normalize() const {
        float mag = magnitude();
        return (mag == 0) ? Vector2(0, 0) : Vector2(x / mag, y / mag);
    }

    // Puntero a los datos no constantes
    float* data() {
        return &x; // Devuelve puntero a la coordenada X
    }

    // Puntero a los datos constantes
    const float* data() const {
        return &x; // Devuelve puntero a la coordenada X
    }
};
