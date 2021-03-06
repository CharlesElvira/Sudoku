// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Sudoku.h"
#include "SudokuSolve.h"
#include <cstdlib>
int main()
{
  int tmp[] = { 0,0,8,9,4,0,0,2,7,
				7,2,6,0,8,0,9,0,0,
				0,0,3,6,0,7,1,8,0,
				6,7,0,5,0,8,4,0,0,
				0,0,5,2,9,0,3,7,0,
				3,0,9,0,0,1,0,5,2,
				9,3,0,0,5,2,0,0,1,
				5,8,0,0,7,0,0,9,4,
				0,6,0,4,0,9,5,0,8 };

  Sudoku *jl = new Sudoku(tmp);
  Sudoku *jl1 = new Sudoku(tmp);
  jl->print();
  SudokuSolve sdk = SudokuSolve(jl);
  SudokuSolve sdk1 = SudokuSolve(jl1);
  sdk1.solve();
  std::cout << "is Sudoku Valid: " << sdk.isSudokuValid();
  sdk.printEmptyVector();
  sdk.solve();
    return 0;
}

