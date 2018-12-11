#include "Cell.h"
#include <cassert>
#include <array> //for addNeighbourList()



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

Cell& Cell::addNeighbourList(std::array<Cell*, 8> newList)
{
    for (int i = 0; i < 8; ++i)
    {
        if (newList[i])
            m_neighbourList[i] = newList[i];
        else
            throw "Incomplete neighbourList given to Cell.addNeighbourList()";
    }
    return *this;
}

Cell&   Cell::operator[](const int index)
{
    assert(index > 0 && index < 9);
    return *m_neighbourList[index];
}


