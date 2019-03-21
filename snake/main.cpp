#include<iostream>
#include "Grid.h"
#include "Snake.h"
#include "Dot.h"
#include "ncurses.h"
#include "time.h"
using namespace std;

int direction = '\0';
int score = 0;
void updateGrid(WINDOW * win, const int size, Snake & tmpSnake, Dot & tmpDot, Grid & tmpGrid);
void detectDirection();
bool checkIfDotEaten( const Snake & tmpSnake, const Dot & tmpDot );
int timeDelayed(unsigned long milisec);

//Main function for Snake game//
int main()
{
initscr();		//Activates the window functions//
WINDOW * win = newwin( 200, 200, 0, 0 );		//Window created with (number of columns, number of rows, starting y location, starting x location)//
noecho();

int size = 15;		//Number of Columns and Rows in Grid//
Snake snake;
snake.addSnakeNode();
snake.moveSnake( (size/2), (size/2) );		//Starting point of snake head//
Dot dot;
dot.generateNewLocation(snake, size);
Grid grid;

nodelay(win, true);		//Used so we have continuous input//
while( !snake.checkEndGame() )
{
updateGrid( win, size, snake, dot, grid );
timeDelayed(110);		//Delay in milliseconds//
}

delwin( win );		//Deallocates window//
printw( "Your Score: %d", score );
getch();
endwin();	

return 0;
}



//Used for continuous input to detect what direction the snake should be moving//
void detectDirection(WINDOW * win)
{
	int ch = wgetch(win);
	switch( ch )
	{
		case 'w':
		{
			if( direction == 's' )
			{
				direction = direction;
			}
			else
			{
				direction = ch;
			}
			break;
		}
		
		case 'a':
		{
			if( direction == 'd' )
			{
				direction = direction;
			}
			else
			{
				direction = ch;
			}
			break;
		}

		case 's':
		{
			if( direction == 'w' )
			{
				direction = direction;
			}
			else
			{
				direction = ch;
			}
			break;
		}
		
		case 'd':
		{			
			if( direction == 'a' )
			{
				direction = direction;
			}
			else
			{
				direction = ch;
			}
			break;
		}
		
		default:
		{
			direction = direction;
			break;
		}
	}
}

//Checks if Dot object was eaten by Snake Head, returns true if Snake Head coordinates are the same as Dot coordinates//
bool checkIfDotEaten( const Snake & tmpSnake, const Dot & tmpDot )
{
	if( (tmpSnake.getHeadXCoordinate() == tmpDot.getXCoordinate()) && (tmpSnake.getHeadYCoordinate() == tmpDot.getYCoordinate()) )
	{
		return true;
	}

	return false;
}

//Updates the grid by checking the direction the snake is moving, checking if the snake object is passing past an edge, moving the snake object depending on if it does or not, checking if a dot was eaten, generating new dot coordinates if it was, and printing the new grid with all the new coordinates.//
void updateGrid(WINDOW * win, const int size, Snake & tmpSnake, Dot & tmpDot, Grid & tmpGrid)
{
	detectDirection(win);
	switch( direction )	//Needs to know where head is moving towards, and if it reaches the edge of the grid//
	{
		case( 'w' ) :
		{
			if( tmpGrid.checkIfPassedEdge(size, tmpSnake.getHeadXCoordinate() - 1, tmpSnake.getHeadYCoordinate()) )
			{
				tmpSnake.moveSnake( (size-1), tmpSnake.getHeadYCoordinate() );
			}
			else
			{
				tmpSnake.moveSnake( tmpSnake.getHeadXCoordinate() - 1, tmpSnake.getHeadYCoordinate() );
			}
		break;
		}
		
		case( 'a' ) :
		{
			if( tmpGrid.checkIfPassedEdge(size, tmpSnake.getHeadXCoordinate(), tmpSnake.getHeadYCoordinate() - 1) )
			{
				tmpSnake.moveSnake( tmpSnake.getHeadXCoordinate(), (size-1) );
			}
			else
			{
				tmpSnake.moveSnake( tmpSnake.getHeadXCoordinate(), tmpSnake.getHeadYCoordinate() - 1 );
			}
		break;
		}

		case( 's' ) :
		{
			if( tmpGrid.checkIfPassedEdge(size, tmpSnake.getHeadXCoordinate() + 1, tmpSnake.getHeadYCoordinate()) )
			{
				tmpSnake.moveSnake( 0, tmpSnake.getHeadYCoordinate() );
			}
			else
			{
				tmpSnake.moveSnake( tmpSnake.getHeadXCoordinate() + 1, tmpSnake.getHeadYCoordinate() );
			}
		break;
		}
	
		case( 'd' ) :
		{
			if( tmpGrid.checkIfPassedEdge(size, tmpSnake.getHeadXCoordinate(), tmpSnake.getHeadYCoordinate() + 1) )
			{
				tmpSnake.moveSnake( tmpSnake.getHeadXCoordinate(), 0 );
			}
			else
			{
				tmpSnake.moveSnake( tmpSnake.getHeadXCoordinate(), tmpSnake.getHeadYCoordinate() + 1 );
			}
		break;
		}
		
	}
	
	if( checkIfDotEaten(tmpSnake, tmpDot) )
	{
		tmpSnake.addSnakeNode();
		tmpDot.generateNewLocation(tmpSnake, size);
		score++;
	}

	tmpGrid.printGrid( win, size, tmpSnake, tmpDot );
}

//Delays time by a passed number of milliseconds//
int timeDelayed(unsigned long milisec)   
{   
    struct timespec req={0};   
    time_t sec=(int)(milisec/1000);   
    milisec=milisec-(sec*1000);   
    req.tv_sec=sec;   
    req.tv_nsec=milisec*1000000L;   
    while(nanosleep(&req,&req)==-1)   
        continue;   
    return 1;   
} 
