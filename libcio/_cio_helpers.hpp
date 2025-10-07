#pragma once
#ifndef CIO_HELPERS_HPP
#define CIO_HELPERS_HPP

/// Misinclude guards.
#ifndef CIO_ADDITIONAL_HEADERS
#error "`_cio_helpers.hpp` was not meant to be included directly, or as part of codefiles other than `cio.hpp`."
#endif

#include <string>
#include <vector>


/* Predef */
void output(const std::vector<std::string>& target);
void output(const std::vector<std::wstring>& target);
std::vector<std::string> separate(const std::string& target, const char separator = ' ');
std::vector<std::wstring> separate(const std::wstring& target, const wchar_t separator = L' ');



/// @brief Outputs a string vector without changes.
/// @note Each member is output on a new line.
/// @param target `std::vector<std::string>` to be output.
void output(const std::vector<std::string>& target)
{
    for (const std::string& element: target)
        std::cout << element << '\n';
}



/// @brief Separates a string into string vector.
/// @param target Target `std::string` to be separated.
/// @param separator `char` that will separate different parts of input. Whitespace by default.
/// @return `std::vector<std::string>` consisting of parts of `target` between and not including `separator`'s.
std::vector<std::string> separate(const std::string& target, const char separator)
{
    std::vector<std::string> result = {""};
    unsigned int i = 0;

    for (const char& c: target)
    {
        /// Adding to the curr word
        if (c != separator)
        {
            result[i] += c;
            continue;
        }

        /// Ignore multiple separators
        if (result[i] == "") continue;

        /// Creating new word
        ++i;
        result.push_back("");
    }

    /// Deleting an empty word if it happens
    while (result[i] == "")
        result.pop_back();
    
    return result;
}


#endif /// CIO_HELPERS_HPP