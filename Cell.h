#ifndef CELL_H
#define CELL_H

#include <vector>

class Cell
{
    private:
        bool m_alive = false;
        std::vector<Cell*> m_neighbourList;
        int m_aliveNeighbours = 0;



    public:
        Cell();
        Cell(bool isAlive);
        ~Cell();

        bool isAlive();
        Cell& kill();
        Cell& unkill();


        Cell& updateState();
        Cell& countAliveNeighbours();

        Cell& operator[](const int index);   // access neighbour
        Cell& operator+(const Cell c2);             // add a cell to neighnbour list

};

#endif // CELL_H
