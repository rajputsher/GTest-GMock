#include "LibraryCode.hpp"
#include <math.h>
#include <stdexcept>
#include <iostream>

double mySqrt(double input)
{
    if (input < 0)
    {
        std::cout<< "Exception thrown\n";
        throw std::runtime_error("Negative argument");
    }
    std::cout<< "No Exception thrown\n";
    return sqrt(input);
}
