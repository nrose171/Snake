#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "Dot.h"
#include "Snake.h"
#include "ncurses.h"
using namespace std;

class Snake;
class Dot; 

class Grid
{
public:
void printGrid( WINDOW * win, const int & size, const Snake & tmpSnake, const Dot & tmpDot);
bool checkIfPassedEdge( const int size, const int futureXCoordinate, const int futureYCoordinate );

private:
const char m_def = '.';	//Default character printed if there is not Snake or Dot object there//
//const char m_def = ' ';	//Use for blank grid//
};

#endif
