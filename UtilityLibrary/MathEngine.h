#pragma once

namespace MathEngine {

    constexpr float PI = 3.14159265358979323846f; // Valor de PI
    constexpr float E = 2.71828182845904523536f; // Valor de E

    /**
     * @brief Calcula la raíz cuadrada mediante el método de Newton-Raphson.
     * @param value El valor para calcular la raíz cuadrada.
     * @return El resultado de la raíz cuadrada.
    */
    inline float sqrt(float value) {
        if (value < 0) return 0; // Devuelve 0 para valores negativos
        float x = value;
        float y = 1.0f;
        constexpr float epsilon = 0.00001f; // Precisión deseada en el cálculo

        while (x - y > epsilon) {
            x = (x + y) / 2.0f;
            y = value / x;
        }
        return x;
    }

    /**
     * @brief Calcula el seno de un ángulo en radianes.
     * @param angle El ángulo en radianes.
     * @return El seno del ángulo.
    */
    inline float sin(float angle) {
        float result = 0.0f;
        float term = angle;
        float angle_squared = angle * angle;
        int n = 1;

        while (term > 1e-6f || term < -1e-6f) {
            result += term; // Suma el término actual al resultado
            term *= -angle_squared / ((2 * n) * (2 * n + 1)); // Calcula el siguiente término
            ++n; // Incrementa el índice del término
        }
        return result;
    }

    /**
     * @brief Calcula el coseno de un ángulo en radianes.
     * @param angle El ángulo en radianes.
     * @return El coseno del ángulo.
    */
    inline float cos(float angle) {
        return sin(angle + PI / 2); // Utiliza la función seno para calcular el coseno
    }

    /**
     * @brief Calcula la tangente de un ángulo en radianes.
     * @param angle El ángulo en radianes.
     * @return La tangente del ángulo.
    */
    inline float tan(float angle) {
        float s = sin(angle);
        float c = cos(angle);
        return (c != 0.0f) ? s / c : 0.0f; // Evita la división por cero
    }
}
