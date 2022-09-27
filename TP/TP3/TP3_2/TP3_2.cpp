#include "TP3_2.hpp"
#include <iostream>

unsigned Point3D::nb_constructed = 0;

inline float get_a_rand()
{
    return rand() % 100 + 1.f;
}

Point3D::Point3D() : x(get_a_rand()), y(get_a_rand()), z(get_a_rand()), nb(Point3D::nb_constructed++)
{
}

Point3D::Point3D(const float &newx, const float &newy, const float &newz) : x(newx), y(newy), z(newz)
{
    nb = nb_constructed++;
}

// Setters and getters

Point3D &Point3D::setXYZ(const float &newx, const float &newy, const float &newz)
{
    x = newx;
    y = newy;
    z = newz;
    return *this;
}

float Point3D::getX()
{
    return x;
}

float Point3D::getY()
{
    return y;
}

float Point3D::getZ()
{
    return z;
};

// other methods
void Point3D::print()
{
    std::cout << "Point number : " << get_nb() << " X = " << getX() << " Y = " << getY() << " Z = " << getZ() << std::endl;
    // From print other : note: candidate function not viable: 'this' argument has type 'const Point3D', but method is not marked const
}

void Point3D::print_other() const
{
    std::cout << "Point number : " << nb << " X = " << x << " Y = " << y << " Z = " << z << std::endl;
}

void Point3D::print(const Point3D &other)
{
    // other.print(); note: candidate function not viable: requires single argument 'other', but no arguments were provided 
    other.print_other();
    // or also working std::cout << "Point number : " << other.nb << " X = " << other.x << " Y = " << other.y << " Z = " << other.z << std::endl;
}

void Trajectory::print()
{
    for (size_t i = 0; i < numberOfPoints; ++i)
    {
        points[i].print();
    }
    std::cout << std::endl;
}

Point3D &Trajectory::getPoint(const size_t &n)
{
    if (n >= numberOfPoints)
    {
        std::cout << " Error in getPoint" << std::endl;
        // not the best method
        exit(EXIT_FAILURE);
    }
    return points[n];
}
unsigned Point3D::get_nb()
{
    return nb;
}