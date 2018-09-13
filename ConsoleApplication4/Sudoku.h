#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>


struct Node {
  int value;
  int numAdj;//Keep tracked of adjacent numbers
  struct Node *adjacentNode[20];//20 adjacent possible numbers
};
class Sudoku
{
private:
  void setRowAdjacencies();
  void setColAdjacencies();
  void setSquareAdjacencies();
  bool nodeExistInAdj(Node *ptr, Node *ptr1);
  void copyNode(Node **output);
  Node *sudokuObject[81];
  int size;
public:
  Sudoku();
  Sudoku(int *sudoku2obj);
  Sudoku(const Sudoku &obj);
  Node **getSudoku();
  int getSudokuAt(int index) const;
  int getSudokuAt(int i, int j) const;
  bool setSudokuAt(int index, int value);
  bool setSudokuAt(int i, int j, int value);
  int getSize() const;
  void print() const;
  virtual ~Sudoku();

};