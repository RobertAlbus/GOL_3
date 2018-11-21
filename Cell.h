#ifndef CELL_H
#define CELL_H

#include <vector>

class Cell
{
    private:
        bool m_alive = false;
        std::vector<Cell*> m_neighbourList;

    public:
        Cell();
        Cell(bool isAlive);
        ~Cell();

        bool isAlive();
        Cell& kill();
        Cell& unkill();

        int countAliveNeighbours();

        Cell& operator[](const int index);   // access neighbour
        Cell& operator+(const Cell c2);             // add a cell to neighnbour list



};

#endif // CELL_H
