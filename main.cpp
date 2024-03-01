#include <iostream>
#include "matrix.h"

int main()
{
  // При запуске программы необходимо создать матрицу с пустым значением 0,...
  matrix_t<int, 0> matrix;
  // ..., заполнить главную диагональ матрицы(от[0, 0] до[9, 9]) значениями от 0 до 9.
  for (int i = 0; i <= 9; ++i)
  {
    matrix[i][i] = i;
  }
  // Второстепенную диагональ (от [0,9] до [9,0]) значениями от 9 до 0.
  for (int i = 0; i <= 9; ++i)
  {
    matrix[i][9-i] = 9-i;
  }
  // Необходимо вывести фрагмент матрицы от[1, 1] до[8, 8]. Между столбцами пробел.
  // Каждая строка матрицы на новой строке консоли.
  for (int i = 1; i <= 8; ++i)
  {
    for (int j = 1; j <= 8; ++j)
    {
      if (j > 1) std::cout << ' ';
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
  // Вывести количество занятых ячеек.
  std::cout << matrix.size() << std::endl;
  // Вывести все занятые ячейки вместе со своими позициями.
  for (auto c : matrix)
  {
    unsigned x;
    unsigned y;
    int v;
    std::tie(x, y, v) = c;
    std::cout << "matrix[" << x << "][" << y << "] = " << v << std::endl;
  }
  // Опционально реализовать N-мерную матрицу
  // (попробовал реализовать методом циклического метапрограммирования... не справился с передачей адреса)
  // Опционально реализовать каноническую форму оператора '=', допускающую выражения
  // ((matrix[100][100] = 314) = 0) = 217
  {
    matrix_t<int, 0> matrix;
    std::cout << "matrix[100][100] = " << matrix[100][100] << ", size = " << matrix.size() << std::endl;
    std::cout << "matrix[100][100] = " << (matrix[100][100] = 314) << ", size = " << matrix.size() << std::endl;
    std::cout << "matrix[100][100] = " << ((matrix[100][100] = 314) = 0) << ", size = " << matrix.size() << std::endl;
    std::cout << "matrix[100][100] = " << (((matrix[100][100] = 314) = 0) = 217) << ", size = " << matrix.size() << std::endl;
  }
  // также см. тесты в файле src/core/test/test_matrix.cpp
  return 0;
}
