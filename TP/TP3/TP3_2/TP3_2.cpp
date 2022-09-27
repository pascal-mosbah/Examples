#include "TP3_2.hpp"
#include <iostream>

unsigned Point3D::nb_constructed  = 0;

inline float get_a_rand(){
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

float Point3D::getZ(){
    return z;
};

// other methods
void Point3D::print(){
        std::cout << "Point number : "<<get_nb()<<" X = "<<getX()<<" Y = "<<getY()<<" Z = "<<getZ()<<std::endl;
}

// float distanceTo(const Point3D &otherPoint3D);

Trajectory::Trajectory()
{
    // for (auto i = 0; i < numberOfPoints; ++i){

    // }
}

void Trajectory::print()
{
    for (size_t i = 0; i < numberOfPoints; ++i){
        points[i].print();
    }
    std::cout<<std::endl;
}
Point3D &Trajectory::getPoint(const size_t &n){
    if (n>=numberOfPoints){
        std::cout<<" Error in getPoint"<<std::endl;
//not the best method
        exit(EXIT_FAILURE);
    }
    return points[n];
}
unsigned Point3D::get_nb(){
    return nb;
}