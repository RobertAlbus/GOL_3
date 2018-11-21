#include "Map2D.h"
#include <cassert>

//ctor
Map2D::Map2D()
{
    init();
}

Map2D::~Map2D()
{
    //dtor
}

Map2D::Map2D(const Map2D& other)
{
    //copy ctor
}

// new cell in each slot of map
CellMatrix Map2D::init()
{
    // ??? new cell must succeed this function call

}

Row Map2D::operator[] (int index)
{
    return m_matrix[index];
}

bool operator== (const Map2D map1, const Map2D map2)
{
    if ((map1.m_height != map2.m_height) || (map1.m_width != map2.m_width))
        return false;

    for (int y = 0; y < map1.m_width; y++)
        for (int x = 0; x < map1.m_width; x++)
        {

        }
}
