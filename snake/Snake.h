#ifndef SNAKE_H
#define SNAKE_H
#include<iostream>
#include"Grid.h"
using namespace std;

class Snake;
class Dot;
class Grid;

class SnakeNode
{
friend class Snake;
friend class Dot;
friend class Grid;
public:

//Def ctor for SnakeNode, sets x and y coordinates to -1 so they do not appear on grid//
SnakeNode() :
	m_next(NULL), m_prior(NULL), xCoordinate(-1), yCoordinate(-1)
{
}

//Parameterized ctor for SnakeNode//
SnakeNode( SnakeNode * prior, SnakeNode * next = NULL ) : 
	m_prior( prior ), m_next( next )
{
}

//Copy ctor for SnakeNode//
SnakeNode( SnakeNode & copy ) :
	m_next( copy.m_next ), m_prior( copy.m_prior ), xCoordinate( copy.getXCoordinate() ), yCoordinate( copy.getYCoordinate() )
{
}

//Assignment operator for SnakeNode//
SnakeNode * operator=( const SnakeNode * cpyNode )
{
	setCoordinates( cpyNode->getXCoordinate(), cpyNode->getYCoordinate() );
	if( cpyNode->m_next != NULL )
	{
	m_next = cpyNode->m_next;
	}
	else
	{
	m_next = NULL;
	}

	if( cpyNode->m_prior != NULL )
	{
	m_prior = cpyNode->m_prior;
	}
	else
	{
	m_prior = NULL;
	}
}

//Sets x and y Coordinate values//
void setCoordinates( const int xValue, const int yValue )
{
	xCoordinate = xValue;
	yCoordinate = yValue;
}

//Returns XCoordinate//
const int getXCoordinate() const
{
	return xCoordinate;
}

//Returns YCoordinate//
const int getYCoordinate() const
{
	return yCoordinate;
}

//Returns character for SnakeNode//
const char getBody() const
{
	return m_body;
}

private:
	int xCoordinate, yCoordinate;	//Location of each SnakeNode//
	const char m_body = 'o';	//Default SnakeNode Character to be printed//
	SnakeNode * m_next;
	SnakeNode * m_prior;
};

class Snake
{
friend class Dot;
friend class Grid;
public:
	Snake();
	Snake(const Snake & cpySnake);
	~Snake();
	Snake & operator=( const Snake & cpySnake );
	const int getSize() const;	//Returns size of list//
	const int getHeadXCoordinate() const;	//Returns x Coordinate of m_head//
	const int getHeadYCoordinate() const;	//Returns y Coordinate of m_head//
	void addSnakeNode();	//Adds a node to the back//
	void deleteSnakeNode();	//Deallocates Node from the front//
	bool checkEndGame();	//Returns true if game is over//
	void moveSnake( const int xCoordinate, const int yCoordinate );	//Moves Head SnakeNode and all Nodes behind it//
	bool empty() const;
	void clear();
	
private:
	SnakeNode * m_head;
	SnakeNode * m_tail;
};

#endif
