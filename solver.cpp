 #include <iostream>
 #include <array>
 #include <vector>
 #include <algorithm> // for std::sort
 
std::array<int, 9> get_row_array(std::array<int, 81>& sudoku, int index)
{
    std::array<int, 9> row;
    int i = index / 9;
    for (size_t j = 0; j < 9; j++)
    {
        row[j] = sudoku[9 * i + j];
    }
    return row;
}

std::array<int, 9> get_col_array(std::array<int, 81>& sudoku, int index)
{
    std::array<int, 9> col;
    int j = index % 9;
    for (size_t i = 0; i < 9; i++)
    {
        col[i] = sudoku[9 * i + j];
    }
    return col;
}

std::array<int, 9> get_box_array(std::array<int, 81>& sudoku, int index)
{
    int i = (index / 9) / 3;
    int j = (index % 9) / 3;
    int start = 27 * (i % 3) + 3 * (j % 3);
    std::array<int, 9> box = 
    {sudoku[start], sudoku[start + 1], sudoku[start + 2],
     sudoku[start + 9], sudoku[start + 10], sudoku[start + 11],
     sudoku[start + 18], sudoku[start + 19], sudoku[start + 20]};

    return box;  
}

bool is_ok(std::array<int, 9> array)
{
    std::sort(array.begin(), array.end());
    for (size_t i = 0; i < 9; i++)
    {
        if (array[i] != 0)
        {
            for (size_t j = i + 1; j < 9; j++)
            {
                if (array[j] == array[i]) return false;
            }
        }
    }
    return true;
}

void print_sudoku(std::array<int,81>& sudoku)
{
    for (size_t i = 0; i < 9; i++)
    {
        std::cout << "|";
        for (size_t j = 0; j < 9; j++)
        {
            std::cout << sudoku[9*i + j] << "|";
        }
        std::cout << '\n';
    }
}

void solve(std::array<int, 81> sudoku)
{
    std::array<int, 81> sudoku_copy = sudoku;
    std::vector<int*> empty_squares;
    std::vector<int> empty_square_locations;

    print_sudoku(sudoku);

    // fill empty squares vector
    for (size_t k = 0; k < 81; k++)
    {
        if (sudoku[k] == 0)
        {
            empty_squares.push_back(&sudoku_copy[k]);
            empty_square_locations.push_back(k);
        }
    }

    bool sudoku_solved = false;
    std::array<int, 9> row;
    std::array<int, 9> col;
    std::array<int, 9> box;
    int index = 0;
    while (not sudoku_solved)
    {
        if (index == -1)
        {
            std::cout << "Solution not found.\n";
            break;
        }
        *(empty_squares[index]) += 1;
        if (*(empty_squares[index]) == 10)
        {
            *(empty_squares[index]) = 0;
            index -= 1;
        }
        else
        {
            int pos = empty_square_locations[index];
            row = get_row_array(sudoku_copy, pos);
            col = get_col_array(sudoku_copy, pos);
            box = get_box_array(sudoku_copy, pos);

            if (is_ok(row) and is_ok(col) and is_ok(box))
            {
                index += 1;
            }           
        }

        if (index == empty_squares.size())
        {
            std::cout << "All done!\n";
            sudoku_solved = true;
        }
    }

    std::cout << "Solution:\n";

    print_sudoku(sudoku_copy);
}
