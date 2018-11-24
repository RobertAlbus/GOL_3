#ifndef CELL_H
#define CELL_H

#include <vector>

class Cell
{
    private:
        bool m_alive = false;
        std::vector<Cell*> m_neighbourList;
        int aliveNeighbours = 0;

    public:
        Cell();
        Cell(bool isAlive);
        ~Cell();

        bool isAlive();
        Cell& kill();
        Cell& unkill();

        int countAliveNeighbours();
        Cell& updateState(); //create me

        Cell& operator[](const int index);   // access neighbour
        Cell& operator+(const Cell c2);             // add a cell to neighnbour list

};

#endif // CELL_H
