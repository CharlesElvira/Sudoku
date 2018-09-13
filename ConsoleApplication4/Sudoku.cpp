
#include "stdafx.h"
#include "Sudoku.h"
Sudoku::Sudoku()
{
  //Initialize Sudoku object create 81 objects in memory
  size = 0;
  for (int i = 0; i < 81; i++)
  {
	sudokuObject[i] = new Node();
	sudokuObject[i]->value = 0;
	sudokuObject[i]->numAdj = 0;
	size++;
  }
  setRowAdjacencies();
  setColAdjacencies();
  setSquareAdjacencies();
}
Sudoku::Sudoku(int *sudoku2obj)
{
  size = 0;
  for (int i = 0; i < 81; i++)
  {
	sudokuObject[i] = new Node();
	sudokuObject[i]->value = sudoku2obj[i];
	sudokuObject[i]->numAdj = 0;
	size++;
  }

  setRowAdjacencies();
  setColAdjacencies();
  setSquareAdjacencies();
}
Sudoku::Sudoku(const Sudoku &obj)
{
  size = obj.size;
  for (int i = 0; i < 81; i++)
  {
	sudokuObject[i]->value = obj.sudokuObject[i]->value;
	sudokuObject[i]->numAdj = obj.sudokuObject[i]->numAdj;
	for (int j = 0; j < obj.sudokuObject[i]->numAdj; j++)
	{
	  sudokuObject[i]->adjacentNode[j]= obj.sudokuObject[i]->adjacentNode[j];
	}
  }
}
void Sudoku::print() const
{
  int count = 0;
  for (int i = 0; i < 81; i++)
  {
	std::cout << sudokuObject[i]->value << " ";
	count++;
	if (count == 9)
	{
	  std::cout << std::endl;
	  count = 0;
	}
  }
}
bool Sudoku::nodeExistInAdj(Node *ptr, Node *ptr1)
{
  for (int i = 0; i < ptr->numAdj; i++)
  {
	if (ptr->adjacentNode[i] == ptr1)
	{
	  return true;
	}
  }

  return false;
}
void Sudoku::setRowAdjacencies()
{
  for (int i = 0; i < 81; i++)//Set Row adjacencies
  {
	int rows = (int)(i / 9);
	int cols = (i % 9);
	if (rows == 0)
	{
	  for (int j = 1; j < 9; j++)
	  {
		sudokuObject[i]->adjacentNode[sudokuObject[i]->numAdj] = sudokuObject[cols + j * 9];
		sudokuObject[i]->numAdj++;
	  }
	}
	else
	{
	  if ((9 - rows) > 0)
	  {
		for (int j = rows + 1; j < 9; j++)
		{
		  sudokuObject[i]->adjacentNode[sudokuObject[i]->numAdj] = sudokuObject[cols + j * 9];
		  sudokuObject[i]->numAdj++;
		}
		for (int j = rows - 1; j >= 0; j--)
		{
		  sudokuObject[i]->adjacentNode[sudokuObject[i]->numAdj] = sudokuObject[cols + j * 9];
		  sudokuObject[i]->numAdj++;
		}
	  }
	}
  }
}
void Sudoku::setColAdjacencies()
{
  for (int i = 0; i < 81; i++)//Set Column adjacencies
  {
	int rows = (int)(i / 9);
	int cols = (i % 9);
	if (cols == 0)
	{
	  for (int j = 1; j < 9; j++)
	  {
		sudokuObject[i]->adjacentNode[sudokuObject[i]->numAdj] = sudokuObject[i + j];
		sudokuObject[i]->numAdj++;
	  }
	}
	else
	{
	  for (int j = 1; j < 9 - cols; j++)
	  {
		sudokuObject[i]->adjacentNode[sudokuObject[i]->numAdj] = sudokuObject[i + j];
		sudokuObject[i]->numAdj++;
	  }
	  for (int j = 1; j <= cols; j++)
	  {
		sudokuObject[i]->adjacentNode[sudokuObject[i]->numAdj] = sudokuObject[i - j];
		sudokuObject[i]->numAdj++;
	  }
	}
  }
}
Node** Sudoku::getSudoku()
{
  return sudokuObject;
}
void Sudoku::copyNode(Node **output)
{
  for (int i = 0; i < 81; i++)
  {
	output[i]->value = sudokuObject[i]->value;
	output[i]->numAdj = sudokuObject[i]->numAdj;
	for (int j = 0; j < output[i]->numAdj; j++)
	{
	  output[i]->adjacentNode[j] = sudokuObject[i]->adjacentNode[j];
	}
  }
}
void Sudoku::setSquareAdjacencies()
{
  int tmp[81];//Create temporary sudoku image to create square adjacencies
  for (int i = 0; i < 81; i++)
  {
	tmp[i] = i;
  }
  int count = 0, count1 = 0, count2 = 0, count3 = 0, nodeCount4 = 0;

  while ((count3 + count2 + count + count1 * 9)<81)
  {

	if (count < 3)
	{
	  tmp[count3 + count2 + count + count1 * 9] = nodeCount4;

	  nodeCount4++;
	  count++;
	}
	else
	{

	  count1++;
	  count = 0;

	}
	if (count1 >= 3)
	{
	  count1 = 0;
	  count2 += 3;
	  std::cout << std::endl;
	}
	if (count2 > 8)
	{
	  count2 = 0;
	  count3 += 27;
	}
  }
  for (int i = 0; i < 81; i++)//Add square adjacencies and avoid duplicate adjacencies
  {
	int rows = (int)(i / 9);
	int cols = (i % 9);
	if (cols == 0)
	{
	  for (int j = 1; j < 9; j++)
	  {
		if (!nodeExistInAdj(sudokuObject[tmp[i]], sudokuObject[tmp[i + j]]))
		{
		  sudokuObject[tmp[i]]->adjacentNode[sudokuObject[tmp[i]]->numAdj] = sudokuObject[tmp[i + j]];
		  sudokuObject[tmp[i]]->numAdj++;
		}
	  }
	}
	else
	{
	  for (int j = 1; j < 9 - cols; j++)
	  {
		if (!nodeExistInAdj(sudokuObject[tmp[i]], sudokuObject[tmp[i + j]]))
		{
		  sudokuObject[tmp[i]]->adjacentNode[sudokuObject[tmp[i]]->numAdj] = sudokuObject[tmp[i + j]];
		  sudokuObject[tmp[i]]->numAdj++;
		}
	  }
	  for (int j = 1; j <= cols; j++)
	  {
		if (!nodeExistInAdj(sudokuObject[tmp[i]], sudokuObject[tmp[i - j]]))
		{
		  sudokuObject[tmp[i]]->adjacentNode[sudokuObject[tmp[i]]->numAdj] = sudokuObject[tmp[i - j]];
		  sudokuObject[tmp[i]]->numAdj++;
		}
	  }
	}
  }
}
bool Sudoku::setSudokuAt(int index, int value)
{
  if (index > size || index < 0)
  {
	return 0;
  }
  else
  {
	sudokuObject[index]->value = value;
	return 1;
  }
}
bool Sudoku::setSudokuAt(int i, int j, int value)
{
  int index = i + j * sqrt(size);
  if (index > size || index < 0)
  {
	return 0;
  }
  else
  {
	sudokuObject[index]->value = value;
	return 1;
  }
}
int Sudoku::getSudokuAt(int index) const
{
  if (index > size || index < 0)
  {
	return -1;
  }
  else
  {
	return 	sudokuObject[index]->value;
  }
}
int Sudoku::getSudokuAt(int i, int j) const
{
  int index = i + j * sqrt(size);
  if (index > size || index < 0)
  {
	return -1;
  }
  else
  {
	return 	sudokuObject[index]->value;
  }
}
int Sudoku::getSize() const
{
  return size;
}
Sudoku::~Sudoku()
{
  for (int i = 0; i < 81; i++)
  {
	delete sudokuObject[i];
  }
}