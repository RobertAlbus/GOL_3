#include "catch.hpp"
#include "Cell.h"
#include <array> // for addNeighbourList() tests

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

    std::array<Cell*, 8> neighbourList;
    for (int i = 0; i < 7; ++i)
    {
        Cell* cell = new Cell;
        neighbourList[i] = cell;
    }

    SECTION( "Incomplete neighbourList should fail" ){
        Cell cell;
        REQUIRE_THROWS( cell.addNeighbourList(neighbourList) );
    }

    Cell* neighbor = new Cell;
    neighbourList[7] = neighbor;

    SECTION( "Complete neighbourList should pass" ){
        Cell cell;
        REQUIRE_NOTHROW( cell.addNeighbourList(neighbourList) );
    }
}

TEST_CASE( "Cell.countAliveNeighbours() tests" ){
}
