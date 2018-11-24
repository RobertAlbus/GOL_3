#include <iostream>
#include "Cell.h"
#include "Map2D.h"
int main()
{
    Cell c1;
    Cell c2;
    Cell c3;
    Cell c4;
    c1 + c2 + c3 + c4;
    // std::cout << c1.countAliveNeighbours();

    Map2D gamemap(4);
    Map2D gamemap2(gamemap);

    gamemap.print();
    std::cout << '\n';







    return 0;
}

