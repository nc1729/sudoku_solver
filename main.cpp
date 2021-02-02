#include <array>
#include <iostream>
#include <chrono>
#include "solver.h"
#include "test.h"

int main()
{
    auto clock_start = std::chrono::steady_clock::now();
    std::array<int, 81> sudoku_to_solve = 
    {0,0,7,3,0,0,2,0,5,
    0,0,4,0,0,9,0,0,0,
    0,0,0,0,0,0,7,6,0,
    4,0,0,0,0,0,0,7,8,
    0,1,0,5,0,0,0,0,2,
    0,0,8,0,0,6,1,0,0,
    0,2,0,0,0,1,4,0,0,
    0,0,0,8,0,0,0,3,7,
    0,0,0,0,0,5,0,0,0};

    solve(sudoku_to_solve);
    auto clock_stop = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_secs = clock_stop - clock_start;
    std::cout << "Time taken: " << elapsed_secs.count() << '\n';
}