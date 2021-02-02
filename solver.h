#pragma once
#include <array>
// Get the row this cell is on
std::array<int, 9> get_row_array(std::array<int, 81>& sudoku, int index);
// Get the column this cell is on
std::array<int, 9> get_col_array(std::array<int, 81>& sudoku, int index);
// Get the box this cell is in (as a 3x3 array)
std::array<int, 9> get_box_array(std::array<int, 81>& sudoku, int index);
// Check if this array contains no duplicate elements (disregarding zeroes)
bool is_ok(std::array<int, 9> array);
// Prints a Sudoku in 'nice' format
void print_sudoku(std::array<int,81>& sudoku);
// Solves a sudoku!
void solve(std::array<int, 81> sudoku);
