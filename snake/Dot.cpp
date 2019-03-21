#include "Dot.h"

//Returns value of xCoordinate of Dot object//
const int Dot::getXCoordinate() const
{
	return xCoordinate;
}

//Returns value of yCoordinate of Dot object//
const int Dot::getYCoordinate() const
{
	return yCoordinate;
}

//Returns character that prints at Dot object location//
const char Dot::getMakeup() const
{
	return m_makeup;
}

//Generates a new location for Dot when it is eaten//
void Dot::generateNewLocation( const Snake & snakeList, const int range )
{
	SnakeNode * curr = snakeList.m_head;
	int xRand = rand() % range;
	int yRand = rand() % range;
	bool check = false;

	while( (curr != NULL) )	//Checks if the Dots new location is at any SnakeNode location//
	{
		if( (xRand != curr->getXCoordinate()) || (yRand != curr->getYCoordinate()) )
		{
			curr = curr->m_next;
		}
		else	//Changes Dot location//
		{
			xRand = rand() % range;
			yRand = rand() % range;
			curr = snakeList.m_head;	//Restarts check for if SnakeNode locations//
		}
	}
			
	curr = NULL;
	xCoordinate = xRand;
	yCoordinate = yRand;
}

