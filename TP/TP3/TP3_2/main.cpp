#include <ctime>
#include <iostream>

#include "TP3_2.hpp"

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    Trajectory trajectory;
    std::cout<<"Print all points"<<std::endl;
    trajectory.print();
    auto &point = trajectory.getPoint(0);
    point.setXYZ(0, 0, 0);
    std::cout<<"Print points[0]"<<std::endl;
    point.print();
    std::cout<<"Print points[8]"<<std::endl;
    trajectory.getPoint(8).setXYZ(8, 8, 8).print(); // talk about indice number !
    std::cout<<"Print points[8]"<<std::endl;
    point.print(trajectory.getPoint(8));
     trajectory.print();
    return EXIT_SUCCESS;
}