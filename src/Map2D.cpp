#include "Map2D.h"
#include <cassert>
#include <random>

//ctor
Map2D::Map2D()
{
    init(44);
}

Map2D::Map2D(int x, int y) : Map2D()
{
    m_height = y;
    m_width = x;
}

Map2D::Map2D(int xy) : Map2D(xy, xy)
{

}

Map2D::~Map2D()
{
    //dtor
}

Map2D::Map2D(const Map2D& other)
{
    this->m_width  = other.m_width;
    this->m_height = other.m_height;
    this->m_matrix = other.m_matrix;
}

// new cell in each slot of map
void Map2D::init(int chance)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,99);

    for (int y = 0; y < m_width; y++)
    {
        Row* row = new Row;
        for (int x = 0; x < m_width; x++)
        {
            Cell* cell = new Cell(true);
            int d100 = distribution(generator);

            if (d100 > chance)
                (*cell).kill();
            (*row).push_back(*cell);
        }
        m_matrix.push_back(*row);
    }

    this->setNeighbourLists();
}


//generate full neighbourlist and pass to new function Cell.addNeighbourList(std::array<Cell*, 8>)
void Map2D::setNeighbourLists()
{
    for (int y = 0; y < m_height; ++y)
        for (int x = 0; x < m_width; ++x)
        {
            bool on_N_edge { y == 0 };
            bool on_E_edge { x == m_width  - 1 };
            bool on_S_edge { y == m_height - 1 };
            bool on_W_edge { x == 0 };

            Cell& cell = m_matrix[y][x];
            std::array<Cell*, 8> neighbourList;

        ////////
        // N
            if (on_N_edge)
                neighbourList[0] = &(m_matrix[m_height - 1][x]);
            else
                neighbourList[0] = &(m_matrix[y - 1][x]);

        ////////
        // NE
            if (on_N_edge && on_E_edge)
                neighbourList[1] = &(m_matrix[m_height - 1][0]);
            else if (on_N_edge && !on_E_edge)
                neighbourList[1] = &(m_matrix[m_height - 1][x + 1]);
            else if (!on_N_edge && on_E_edge)
                neighbourList[1] = &(m_matrix[y - 1][0]);
            else if (!on_N_edge && !on_E_edge)
                neighbourList[1] = &(m_matrix[y - 1][x + 1]);
        ////////
        // E
            if (on_E_edge)
                neighbourList[2] = &(m_matrix[y][0]);
            else
                neighbourList[2] = &(m_matrix[y][x + 1]);

        ////////
        // SE
            if (on_S_edge && on_E_edge)
                neighbourList[3] = &(m_matrix[0][0]);
            else if (on_S_edge && !on_E_edge)
                neighbourList[3] = &(m_matrix[0][x + 1]);
            else if (!on_S_edge && on_E_edge)
                neighbourList[3] = &(m_matrix[y + 1][0]);
            else if (!on_S_edge && !on_E_edge)
                neighbourList[3] = &(m_matrix[y + 1][x + 1]);

        ////////
        // S
            if (on_S_edge)
                neighbourList[4] = &(m_matrix[0][x]);
            else
                neighbourList[4] = &(m_matrix[y + 1][x]);

        ////////
        // SW
            if (on_S_edge && on_W_edge)
                neighbourList[5] = &(m_matrix[0][m_width - 1]);
            else if (on_S_edge && !on_W_edge)
                neighbourList[5] = &(m_matrix[0][x - 1]);
            else if (!on_S_edge && on_W_edge)
                neighbourList[5] = &(m_matrix[y + 1][m_width - 1]);
            else if (!on_S_edge && !on_W_edge)
                neighbourList[5] = &(m_matrix[y + 1][x - 1]);

        ////////
        // W
            if (on_W_edge)
                neighbourList[6] = &(m_matrix[y][m_width - 1]);
            else
                neighbourList[6] = &(m_matrix[y][x - 1]);

        ////////
        // NW
            if (on_N_edge && on_W_edge)
                neighbourList[7] = &(m_matrix[m_height - 1][m_width - 1]);
            else if (on_N_edge && !on_W_edge)
                neighbourList[7] = &(m_matrix[m_height - 1][x - 1]);
            else if (!on_N_edge && on_W_edge)
                neighbourList[7] = &(m_matrix[y - 1][m_width - 1]);
            else if (!on_N_edge && !on_W_edge)
                neighbourList[7] = &(m_matrix[y - 1][x - 1]);

            cell.addNeighbourList(neighbourList);
        }
}

Map2D& Map2D::updateState()
{
    for (Row row : m_matrix)
        for (Cell cell : row)
        {
            cell.countAliveNeighbours();
        }
    for (Row row : m_matrix)
        for (Cell cell : row)
        {
            cell.updateState();
        }

}

Map2D::Row Map2D::operator[] (int index)
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
    return true;
}
////////////////
//
// UTILS
//
////////////////
#include <iostream>
#include <string>

void Map2D::size()
{
    std::cout << m_width << " x " << m_height;
}

Map2D& Map2D::print()
{
    std::string printOut;
    for (auto row : m_matrix)
    {
        printOut += '\t';
        for (Cell cell : row)
        {
            if ( cell.isAlive() )
                printOut += ". ";
            else
                printOut += "  ";
        }
        printOut += '\n';
    }
    std::cout << printOut;
}



