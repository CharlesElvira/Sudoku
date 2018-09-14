#pragma once
#include "Sudoku.h"
#include <vector>
class SudokuSolve
{
private:
  std::vector<int> *emptyVector;
  Node **tmpsdk;
  Sudoku *sudoku;
  Sudoku *solveSudoku;
  int sizeEmptyVector;
public:
  SudokuSolve();
  SudokuSolve(Sudoku *sdk);
  bool isSudokuValid();
  int getSizeEmptyVector() const;
  void printEmptyVector() const;
  void solve1( Node **node, std::vector<int> *emptyVec);
  Sudoku* solve();
  virtual ~SudokuSolve();
};

