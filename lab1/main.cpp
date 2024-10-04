#include <iostream>
#include "include/extract_numbers.h"

int main() {
    std::string input;
    std::cout << "Enter a string with numbers and letters: ";
    std::cin >> input;

    std::string result = extract_numbers(input);
    std::cout << "Extracted numbers: " << result << std::endl;

    return 0;
}
