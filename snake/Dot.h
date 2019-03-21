#ifndef DOT_H
#define DOT_H

#include "Snake.h"
#include "Grid.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Snake;

class Dot
{
friend class Grid;	//Grid needs to update dots x and y coordinates//
public:
const int getXCoordinate() const;
const int getYCoordinate() const;
const char getMakeup() const;
void generateNewLocation( const Snake & snakeList, const int range );

private:
const char m_makeup = '*';	//Character used for what the dot looks like//
int xCoordinate, yCoordinate;
};

#endif
