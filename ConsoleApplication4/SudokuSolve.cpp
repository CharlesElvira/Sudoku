#include "stdafx.h"
#include "SudokuSolve.h"


SudokuSolve::SudokuSolve()
{
  sizeEmptyArray = 0;
}
SudokuSolve::SudokuSolve(Sudoku *sdk)
{

  tmpsdk= sdk->getSudoku(); //get the node sudoku to copy all the empty index
  int tmp[81];
  for (int i = 0; i < 81; i++)
  {
	tmp[i] = 0;
  }
  sizeEmptyArray = 0;

  for (int i = 0; i < 81; i++)
  {
	if (tmpsdk[i]->value == 0)
	{
	  tmp[sizeEmptyArray] = i;
	  sizeEmptyArray++;
	}
  }

  emptyArray=new int[sizeEmptyArray]();
  sizeEmptyArray = 0;

  for (int i = 0; i < 81; i++)
  {
	if (tmp[i]!= 0)
	{
	  emptyArray[sizeEmptyArray] = tmp[i];
	  sizeEmptyArray++;
	}
  }

}

SudokuSolve::~SudokuSolve()
{
}
