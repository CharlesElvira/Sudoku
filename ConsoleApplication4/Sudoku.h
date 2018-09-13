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
  Node * sudokuObject[81];
public:
  Sudoku();
  void print();
  virtual ~Sudoku();

};