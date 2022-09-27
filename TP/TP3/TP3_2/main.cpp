#include<ctime>

#include "TP3_2.hpp"

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    
    Trajectory trajectory;
    trajectory.print();
    auto &point = trajectory.getPoint(0);
    point.print();
    trajectory.getPoint(8).setXYZ(8, 8, 8).print(); //talk about indice number

    return EXIT_SUCCESS;
}