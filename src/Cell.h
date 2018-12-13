#ifndef CELL_H
#define CELL_H

#include <array> // for m_neighbourList

class Cell
{
    private:
        bool m_alive = false;
        std::array<Cell*, 8> m_neighbourList;
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
        Cell& addNeighbourList(std::array<Cell*, 8> newList);

        Cell& operator[](const int index);   // access neighbour
};

#endif // CELL_H
