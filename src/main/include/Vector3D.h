#pragma once

struct Vector3D
{
    double x, y, z;

    Vector3D(double t_x, double t_y, double t_z)
    {
        x = t_x;
        y = t_y;
        z = t_z;
    };

    Vector3D() {
        x = 0;
        y = 0;
        z = 0;
    };

    Vector3D(Vector3D &t_vector)
    {
        x = t_vector.x;
        y = t_vector.y;
        z = t_vector.z;
    };


    void set(const Vector3D &t_vector)
    {
        x = t_vector.x;
        y = t_vector.y;
        z = t_vector.z;
    }

    void set(double t_x, double t_y, double t_z)
    {
        x = t_x;
        y = t_y;
        z = t_z;
    }

    Vector3D get()
    { return Vector3D{x, y, z}; }

    // Addition & Subtraction
    Vector3D operator + (const Vector3D &t_vector)
    { return Vector3D{x + t_vector.x, y + t_vector.y, z + t_vector.z}; }

    Vector3D operator - (const Vector3D &t_vector)
    { return Vector3D{x - t_vector.x, y - t_vector.y, z - t_vector.z}; }

    // Division & Multiplication
    Vector3D mult(double value)
    { return Vector3D{x / value, y / value, z / value}; }

    Vector3D div(double value)
    { return Vector3D{x * value, y * value, z * value}; }

    Vector3D operator / (const Vector3D &t_vector)
    { return Vector3D{x / t_vector.x, y / t_vector.y, z / t_vector.z}; }

    Vector3D operator * (const Vector3D &t_vector)
    { return Vector3D{x * t_vector.x, y * t_vector.y, z * t_vector.z}; }

    // Other
    Vector3D minimum(double value)
    {
        return Vector3D
        {
            (fabs(x) < value ? x : value),
            (fabs(y) < value ? y : value),
            (fabs(z) < value ? z : value)
        };
    }

    Vector3D minimum(const Vector3D &t_vector)
    {
        return Vector3D
        {
            (fabs(x) < t_vector.x ? x : t_vector.x),
            (fabs(y) < t_vector.y ? y : t_vector.y),
            (fabs(z) < t_vector.z ? z : t_vector.z)
        };
    }

    Vector3D maximum(double value)
    {
        return Vector3D
        {
            (fabs(x) > value ? x : value),
            (fabs(y) > value ? y : value),
            (fabs(z) > value ? z : value)
        };
    }

    Vector3D maximum(const Vector3D &t_vector)
    {
        return Vector3D
        {
            (fabs(x) > t_vector.x ? x : t_vector.x),
            (fabs(y) > t_vector.y ? y : t_vector.y),
            (fabs(z) > t_vector.z ? z : t_vector.z)
        };
    }

    Vector3D deadzone(const Vector3D &t_vector)
    {
        return Vector3D
        {
            (fabs(x) > t_vector.x ? x : 0),
            (fabs(y) > t_vector.y ? y : 0),
            (fabs(z) > t_vector.z ? z : 0)
        };
    }

    Vector3D deadzone(double value)
    {
        return Vector3D
        {
            (fabs(x) > value ? x : 0),
            (fabs(y) > value ? y : 0),
            (fabs(z) > value ? z : 0)
        };
    }

    static Vector3D zero()
    { return Vector3D{0, 0, 0}; }

    static Vector3D one()
    { return Vector3D{1, 1, 1}; }
};