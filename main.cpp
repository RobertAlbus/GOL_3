#include <iostream>
#include "Cell.h"

int main()
{
    Cell c1;
    Cell c2;
    Cell c3;
    Cell c4;



    c1 + c2 + c3 + c4;

    // does not work
    std::cout << c1.countAliveNeighbours();

    return 0;
}

