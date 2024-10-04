#include "../include/extract_numbers.h"

std::string extract_numbers(const std::string& input) {
    std::string result;
    bool in_number = false;

    for (char c : input) {
        if (isdigit(c)) {
            if (!in_number && !result.empty()) {
                result += ' ';
            }
            result += c;
            in_number = true;
        } else {
            in_number = false;
        }
    }

    return result;
}
