#include "some_defines.hpp"

Plane::Plane(){}

Plane::Plane(const string &identification) : identification_(identification) {}

ostream &operator<<(ostream &os, const Airport &airport)
{
    os << "Available planes\n";
    for (auto &plane : airport.planes)
    {
        os << plane.identification_ << endl;
    }
    return os;
}

bool Waiting_planes::is_a_plane_available()
{
    return !(planes.empty());
}

Plane_wrapping::Plane_wrapping(const string &identification) : Plane(identification) {}

Plane_wrapping::Plane_wrapping() : Plane("0") {}
