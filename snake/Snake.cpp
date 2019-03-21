#include "Snake.h"

//Default ctor for Snake object, creates empty list//
Snake::Snake() :
	m_head(NULL), m_tail(NULL)
{
}

//Paramaterized ctor for Snake object//
Snake::Snake( const Snake & cpySnake )
{
	if( !cpySnake.empty() )
	{
		SnakeNode * copyCurr = cpySnake.m_head;
		while( copyCurr != NULL )
		{
			addSnakeNode();
			copyCurr = copyCurr->m_next;
		}
	}
}

//Assignment operator for Snake objects//
Snake & Snake::operator=( const Snake & cpySnake )
{
	if( !cpySnake.empty() )
	{
		if( !this->empty() )
		{
			this->clear();
		}

		SnakeNode * copyCurr = cpySnake.m_head;
		while( copyCurr != NULL )
		{
			addSnakeNode();
			copyCurr = copyCurr->m_next;
		}
	}
}

//Dtor for Snake object//
Snake::~Snake()
{
clear();
cout << "dtor called" << endl;
}

//Returns size of Snake object//
const int Snake::getSize() const
{
	if( !empty() )
	{
		int counter = 0;
		SnakeNode * curr = m_head;
		while( curr != NULL )
		{
			counter++;
			curr = curr->m_next;
		}
		curr = NULL;
	}
}

//Returns X coordinate of head SnakeNode//
const int Snake::getHeadXCoordinate() const
{
	return m_head->getXCoordinate();
}

//Returns Y coordinate of head SnakeNode//
const int Snake::getHeadYCoordinate() const
{
	return m_head->getYCoordinate();
}

//Adds a SnakeNode to the back of the Snake//
void Snake::addSnakeNode()
{
	SnakeNode * newNode = new SnakeNode;
	if( !empty() )	//Adds a new SnakeNode to an existing list//
	{
		m_tail->m_next = newNode;
		newNode->m_prior = m_tail;
		m_tail = NULL;
		m_tail = newNode;
	} 
	else	//Adds a new SnakeNode to an empty list//
	{
		m_head = NULL;
		m_head = newNode;
		m_tail = NULL;
		m_tail = newNode;
	}
}

//Deallocates head snake nodes memory//
void Snake::deleteSnakeNode()
{
	SnakeNode * delP = m_head;
	m_head = m_head->m_next;
	delete delP;
	delP = NULL;
}

//Deallocates all memory from Snake object//
void Snake::clear()
{
	SnakeNode * curr = m_head;
	while( curr != NULL )
	{
		deleteSnakeNode();
		curr = curr->m_next;
	}
	curr = NULL;
}

//Checks if Snake is empty of not//
bool Snake::empty() const
{
	return !m_head;
}

//Checks if the Snake Head touches any of its body Nodes, returns true if game is over//
bool Snake::checkEndGame()
{
	SnakeNode * curr = m_head->m_next;
	while( curr != NULL )	//Traverses through entire list and makes sure head SnakeNode does not have same coordinates as any other SnakeNode//
	{
		if( (m_head->getXCoordinate() == curr->getXCoordinate()) && (m_head->getYCoordinate() == curr->getYCoordinate()) )
		{
			return true;
		}
	curr = curr->m_next;
	}
	curr = NULL;
	return false;
}

//Changes the coordinates of the head SnakeNode and transfers coordinates to the next node in line until the tail node is reached//
void Snake::moveSnake(const int xCoordinate, const int yCoordinate)
{
	SnakeNode * curr = m_tail;
	SnakeNode * priorCurr = m_tail->m_prior;
	while( curr != m_head )	//Traverses list starting from the tail end//
	{
		curr->setCoordinates( priorCurr->getXCoordinate(), priorCurr->getYCoordinate() );	//Sets the current SnakeNode's coordinates to the m_prior SnakeNode's coordinates//
		curr = curr->m_prior;
		priorCurr = priorCurr->m_prior;
	}

	m_head->setCoordinates( xCoordinate, yCoordinate );	//Sets head SnakeNode to passed new Coordinates//
	curr = NULL;
	priorCurr = NULL;
}















