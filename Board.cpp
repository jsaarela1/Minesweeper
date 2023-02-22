#include "Board.h"

Board::Board()
{
	_columns = 0;
	_rows = 0;
	//_mines = 0;
}

Board::Board(int columns, int rows)
{
	_columns = columns;
	_rows = rows;
}