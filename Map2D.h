#ifndef MAP2D_H
#define MAP2D_H

#include <vector>
#include "Cell.h"




class Map2D
{
    using Row       = std::vector<Cell>;
    using Matrix    = std::vector<Row>;

    public:
        Map2D();
        Map2D(int x, int y);
        Map2D(int xy);
        ~Map2D();
        Map2D(const Map2D& other);


        friend bool operator== (const Map2D map1, const Map2D map2);
        Row operator[] (int index);

    protected:

    private:
        int m_width = 40;
        int m_height = 40;

        Matrix m_matrix;

        void init();

        int countAliveNeighbours();
        Map2D& updateState();

};

#endif // MAP2D_H
