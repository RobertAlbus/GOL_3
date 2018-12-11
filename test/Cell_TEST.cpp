#include "catch.hpp"
#include "Cell.h"

TEST_CASE( "Cell constructors tests" ){

    SECTION( "Cell() should create dead cell" ){
        Cell cell;
        REQUIRE( cell.isAlive() == false );
    }
    SECTION( "Cell(true) should create alive cell" ){
        Cell cell(true);
        REQUIRE( cell.isAlive() == true );
    }
    SECTION( "Cell(false) should create dead cell" ){
        Cell cell(false);
        REQUIRE( cell.isAlive() == false );
    }
}

TEST_CASE( "Cell state management tests"){

    Cell cell(true);

    SECTION( "Cell.isAlive() should return a bool" ){
        REQUIRE( typeid(cell.isAlive()) == typeid(true) );
    }

    SECTION( "Cell.kill() should kill cell and return self" ){

        REQUIRE( cell.kill().isAlive() == false );
    }

    cell.kill();
    SECTION( "Cell.unkill() should unkill cell and return self" ){
        REQUIRE( cell.unkill().isAlive() == true );
    }
}

TEST_CASE( "Cell.addNeighbourList() tests" ){

    #include <array>

    Cell cell(true);
    std::array<Cell*, 8> newList;
    for (int i = 0; i < 4; ++i)
        newList[i] = new Cell(true);
    for (int i = 0; i < 4; ++i)
        newList[i + 4] = new Cell(false);

    cell.addNeighbourList(newList);
}


// update the addNeighbour functionality to take in array<Cell*, 8>
// this will fix the ability to over- or under-assign neighbours to a cell
TEST_CASE( "Cell.countAliveNeighbours() tests" ){
}
