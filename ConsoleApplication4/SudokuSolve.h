#pragma once
#include "Sudoku.h"
class SudokuSolve
{
private:
  int *emptyArray;
  Node **tmpsdk;
  int sizeEmptyArray;
public:
  SudokuSolve();
  SudokuSolve(Sudoku *sdk);
  Sudoku* solveSudoku();
  virtual ~SudokuSolve();
};

