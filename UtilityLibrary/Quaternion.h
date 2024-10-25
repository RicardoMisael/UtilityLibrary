#pragma once
#include "MathEngine.h"
#include "Vector3.h"

class Quaternion {
public:
    // Partes del cuaternión: componente escalar y partes vectoriales (w, x, y, z).
    float w, x, y, z;

    /**
     * @brief Constructor por defecto.
     * Inicializa las componentes del cuaternión a (0, 0, 0, 0).
     */
    Quaternion() : w(0), x(0), y(0), z(0) {}

    /**
     * @brief Constructor parametrizado.
     * Inicializa las componentes del cuaternión con los valores especificados.
     * @param w Componente escalar
     * @param x Componente X
     * @param y Componente Y
     * @param z Componente Z
     */
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    /**
     * @brief Constructor que inicializa un cuaternión a partir de un ángulo y un eje de rotación.
     * @param angle Ángulo en radianes.
     * @param axis Eje de rotación.
     */
    Quaternion(float angle, const Vector3& axis) {
        float halfAngle = angle / 2.0f;
        float sinHalfAngle = MathEngine::sin(halfAngle);
        w = MathEngine::cos(halfAngle);
        x = axis.x * sinHalfAngle;
        y = axis.y * sinHalfAngle;
        z = axis.z * sinHalfAngle;
    }

    // Sobrecarga del operador + para sumar dos cuaterniones.
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
    }

    // Sobrecarga del operador - para restar dos cuaterniones.
    Quaternion operator-(const Quaternion& other) const {
        return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
    }

    // Sobrecarga del operador * para multiplicar un cuaternión por un escalar.
    Quaternion operator*(float scalar) const {
        return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
    }

    // Sobrecarga del operador * para multiplicar dos cuaterniones.
    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    /**
     * @brief Calcula la magnitud del cuaternión.
     * @return Magnitud del cuaternión.
     */
    float magnitude() const {
        return MathEngine::sqrt(w * w + x * x + y * y + z * z);
    }

    /**
     * @brief Normaliza el cuaternión.
     * @return Un cuaternión normalizado con magnitud 1.
     * Si la magnitud es 0, se devuelve un cuaternión nulo.
     */
    Quaternion normalize() const {
        float mag = magnitude();
        return (mag == 0) ? Quaternion(0, 0, 0, 0) : Quaternion(w / mag, x / mag, y / mag, z / mag);
    }

    /**
     * @brief Calcula el conjugado del cuaternión.
     * @return El cuaternión conjugado.
     */
    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }

    /**
     * @brief Calcula el inverso del cuaternión.
     * @return El cuaternión inverso.
     */
    Quaternion inverse() const {
        float magSquared = w * w + x * x + y * y + z * z;
        return (magSquared == 0) ? Quaternion(0, 0, 0, 0) : conjugate() * (1.0f / magSquared);
    }

    /**
     * @brief Rota un vector utilizando el cuaternión.
     * @param v Vector a rotar.
     * @return El vector rotado.
     */
    Vector3 rotate(const Vector3& v) const {
        Quaternion qv(0, v.x, v.y, v.z);
        Quaternion result = (*this) * qv * inverse();
        return Vector3(result.x, result.y, result.z);
    }

    // Devuelve un puntero no constante a los datos del cuaternión.
    float* data() {
        return &w; // Puntero a la componente escalar
    }

    // Devuelve un puntero constante a los datos del cuaternión.
    const float* data() const {
        return &w; // Puntero a la componente escalar
    }
};
