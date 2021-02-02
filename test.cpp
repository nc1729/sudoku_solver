#include <array>
#include <cassert>
#include "solver.h"

void test_is_ok()
{
    std::array<int, 9> test_array = {1,2,3,4,5,6,7,8,9};
    std::array<int, 9> test_array2 = {7,0,0,2,6,1,4,0,3};
    std::array<int, 9> test_array3 = {0,0,0,1,1,2,3,4,5};
    assert(is_ok(test_array));
    assert(is_ok(test_array2));
    assert(not is_ok(test_array3));
}

void run_tests()
{
    test_is_ok();
}