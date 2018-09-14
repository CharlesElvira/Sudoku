#include "stdafx.h"
#include "SudokuSolve.h"


SudokuSolve::SudokuSolve()
{
  sizeEmptyVector = 0;
  emptyVector = new std::vector<int>();
}
SudokuSolve::SudokuSolve(Sudoku *sdk)
{

  sudoku = sdk; //get the node sudoku to copy all the empty index
  tmpsdk = sdk->getSudoku();
  solveSudoku = new Sudoku(*sdk);
  sizeEmptyVector = 0;
  emptyVector = new std::vector<int>();
  for (int i = 0; i < 81; i++)
  {
	if (tmpsdk[i]->value == 0)
	{
	  emptyVector->push_back(i);
	  sizeEmptyVector++;
	}
  }
}
bool SudokuSolve::isSudokuValid()
{
  for (int i = 0; i < 81; i++)
  {
	for (int j = 0; j < 20; j++)
	{
	  if (tmpsdk[i]->adjacentNode[j]->value != 0 && tmpsdk[i]->adjacentNode[j]->value == tmpsdk[i]->value)
	  {
		return 0;
	  }
	}
  }
  return 1;
}
Sudoku* SudokuSolve::solve()
{

  tmpsdk = solveSudoku->getSudoku();
  solveSudoku->print();
  solve1(tmpsdk, emptyVector);

  return solveSudoku;
}
void SudokuSolve::solve1(Node **node, std::vector<int> *emptyVec)
{
  std::vector<int> *emptyTemp = new std::vector<int>();
  int arrayofvalue[] = { 0,0,0,0,0,0,0,0,0 };
  int sizearrayofvalue = 0;

  if (emptyVec->size() > 0)
  {
	int tmp = emptyVec->back();
	for (int i = 0; i < 20;i++)
	{
	  if (node[tmp]->adjacentNode[i]->value != 0)
	  {
		if (arrayofvalue[node[tmp]->adjacentNode[i]->value - 1] == 0)
		{
		  sizearrayofvalue++;
		}
		arrayofvalue[node[tmp]->adjacentNode[i]->value-1]= node[tmp]->adjacentNode[i]->value;
	  }
	}
	if (sizearrayofvalue == 8)
	{
	  int j = 0;
	  while(arrayofvalue[j]>0)
	  {
		j++;
	  }
	  node[tmp]->value = j + 1;
	  emptyVec->pop_back();
	  SudokuSolve::solve1(node, emptyVec);
	}
	else
	{
	  emptyTemp->push_back(emptyVec->back());
	  emptyVec->pop_back();
	  for (int i = 0; i < emptyVec->size(); i++)
	  {
		emptyTemp->push_back(emptyVec->at(i));
	  }
	  emptyVec->swap(*emptyTemp);
	  SudokuSolve::solve1(node, emptyVec);
	}

  }
  delete emptyTemp;
}
int SudokuSolve::getSizeEmptyVector()const
{
  return emptyVector->size();
}
void SudokuSolve::printEmptyVector() const
{
  if (sizeEmptyVector > 0)
  {
	for (int i = 0; i < sizeEmptyVector; i++)
	{
	  std::cout << emptyVector->at(i) << " ";
	}
  }
}
SudokuSolve::~SudokuSolve()
{
}
