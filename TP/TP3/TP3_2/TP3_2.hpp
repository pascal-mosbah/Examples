#pragma once
#include <cstdlib>

class Point3D {
	private:
		float x,y,z;   // private attributes
        static unsigned nb_constructed;
        unsigned nb;
	public:
		// constuctors
		Point3D(); // fill X Y Z with random values (from 0 to 100)
		Point3D(const float &newx, const float &newy, const float &newz); // fill XYZ values
		
		// Setters and getters
		Point3D &setXYZ(const float &newx, const float &newy, const float &newz);
		// void setX(const float &newx);
		// void setY(const float &newy);
		// void setZ(const float &newz);
		float getX();
		float getY();
		float getZ();

        unsigned get_nb();

		void print();    // prints the coordinates of the point

		// other methods
		// float distanceTo(const Point3D &otherPoint3D);
};

constexpr size_t numberOfPoints = 10;
class Trajectory{
	private:
		Point3D points[numberOfPoints];
	public:
        Trajectory();
		void print(); // print the coordinates of all points
		Point3D & getPoint(const size_t &n); // returns the reference of point n
		float getTotalDistance();
};
