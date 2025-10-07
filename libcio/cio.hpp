#pragma once
#ifndef CIO_MAIN_HPP
#define CIO_MAIN_HPP

/// Misinclude guards.
#define CIO_ADDITIONAL_HEADERS
#include "_cio_design.hpp"
#include "_cio_helpers.hpp"

#include <iostream>
#include <string.h>
#include <vector>



/// @brief Console, standard string input-output wrapper.
/// @note Based on `std::string`; `std::wstring` implementation available as `wcio`.
namespace cio
{
    /* Predef */
    std::vector<std::string> general_input(const char separator = ' ');


    /// @brief Reads and separates user input, without altering or acting on it. Outputs a `"> "` before input.
    /// @param separator `char` that will separate different parts of input. Whitespace by default.
    /// @return `std::vector<std::string>` of separated user input.
    std::vector<std::string> general_input(const char separator)
    {
        std::cout << "> ";
        std::string input = std::string();
        getline(std::cin, input);

        std::vector<std::string> separated_input = separate(input, separator);
        return separated_input;
    }
}



/// @brief Console, wstring input-output wrapper.
/// @note Based on `std::wstring`; `std::string` implementation available as `cio`.
namespace wcio
{

}


#undef CIO_ADDITIONAL_HEADERS
#endif /// CIO_MAIN_HPP