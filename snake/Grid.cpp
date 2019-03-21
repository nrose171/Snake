#include "Grid.h"

//Outputs the characters of SnakeNodes and Dot objects at their locations, and fills the rest with default characters. Outputs all to the passed window//
void Grid::printGrid(WINDOW * win, const int & size, const Snake & tmpSnake, const Dot & tmpDot)
{
	SnakeNode * curr = tmpSnake.m_head;
	bool check = false;	//bool value to determine if there is a SnakeNode or Dot character in the (x,y) coordinate//

	for( int xValue = 0; xValue < size; xValue++ )	//2D Grid Row Loop which is equivalent to a yCoordinate//
	{
		for( int yValue = 0; yValue < size; yValue++ )	//2D Grid Column Loop which is equivalent to an xCoordinate//
		{
			wmove( win, xValue, yValue); //Moves Cursor to an x, y location//
			if ( (tmpDot.getXCoordinate() == xValue) && (tmpDot.getYCoordinate() == yValue) )  //Checks for (x,y) Coordinates of Dot object//
			{
				//wmove( win, xValue, yValue );
				waddch( win, tmpDot.getMakeup() );
				check = true;	//location is filled with Dot object//
			}
				
			while( (curr != NULL) && (!check) )	//Checks each SnakeNode for each (x,y) coordinate in grid//
			{
				if( (curr->getXCoordinate() == xValue) && (curr->getYCoordinate() == yValue) )
				{
					//wmove( win, xValue, yValue );
					waddch( win, curr->getBody() );	//Outputs SnakeNode to Window at Cursor//
					check = true;	//location is filled with a SnakeNode object//
				}
				curr = curr->m_next;
			}
			curr = tmpSnake.m_head;  //Resets curr pointer to the head node//
			
			if( !check )	//If check == false, the (x,y) coordinate is a default character//
			{
				//wmove( win, xValue, yValue );
				waddch( win, m_def );	//Outputs default character to window at Cursor//
			}
			else	//Reset Check
			{
					check = false;
			}
			
		}
		
		waddch( win, '\n' );	//Outputs a newLine character to the window//
	}
	curr = NULL;
	wrefresh(win);	//Refresh the window//
}

//Checks if the Snake node has passed an edge of the grid//
bool Grid::checkIfPassedEdge( const int size, const int futureXCoordinate, const int futureYCoordinate )
{
	if( futureXCoordinate < 0 || futureXCoordinate >= size || futureYCoordinate < 0 || futureYCoordinate >= size )
	{
		return true;
	}

return false;
}
