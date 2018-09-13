// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Sudoku.h"
#include "SudokuSolve.h"
#include <cstdlib>
int main()
{
  int tmp[81];
  for (int i = 0; i < 81; i++)
  {
	tmp[i] = std::rand()%9;
  }
  Sudoku *jl = new Sudoku(tmp);
  jl->print();
  SudokuSolve sdk = SudokuSolve(jl);

    return 0;
}

