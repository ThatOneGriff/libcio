#include <iostream>
#include <vector>
#include "libcio/cio.hpp"


int main()
{
    std::vector<std::string> input = cio::general_input();
    output(input);

    return 0;
}