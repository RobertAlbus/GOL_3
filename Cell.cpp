#include "Cell.h"
#include <cassert>

Cell::Cell(){}
Cell::Cell(bool isAlive) : m_alive(isAlive) {}
Cell::~Cell(){}

bool    Cell::isAlive() { return m_alive; }
Cell&   Cell::kill()    { m_alive = false; return *this; }
Cell&   Cell::unkill()  { m_alive = true;  return *this; }

Cell&   Cell::countAliveNeighbours()
{
    int aliveNeighbours = 0;
    for (auto cell : m_neighbourList)
        if (cell->isAlive())
            ++aliveNeighbours;
    m_aliveNeighbours = aliveNeighbours;
    return *this;
}

Cell&   Cell::updateState()
{
    if (m_alive)
    {
        if (m_aliveNeighbours > 4 || m_aliveNeighbours < 3)
        this->kill();
    }
    else
    {
        if (m_aliveNeighbours <= 4 || m_aliveNeighbours >= 3)
            this->unkill();
    }
}

Cell&   Cell::operator[](const int index)    // access neighbour
{
    assert(index > 0 && index < 9);
    return *m_neighbourList[index];
}
Cell&   Cell::operator+(Cell c2)       // add a cell to neighnbour list
{
    this->m_neighbourList.push_back((&c2));
    return *this;
}


