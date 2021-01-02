#include <iostream>
#include "LibraryCode.hpp"
#include <vector>

std::vector<int> inputVector{1,-2, 3, -4, 5, -6, -7};

int main(int argc, char **argv)
{
    std::cout << "Actual application code \n";
    std::cout << "Number of positives in {1,-2, 3, -4, 5, -6, -7} =" << countPositives(inputVector) << "\n";
    return 0;
}