#include <gtest/gtest.h>
#include "../include/extract_numbers.h"

TEST(ExtractNumbersTest, HandlesMixedInput) {
    std::string input = "abc123def456";
    std::string expected = "123 456";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesNoNumbers) {
    std::string input = "abcdef";
    std::string expected = "";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesOnlyNumbers) {
    std::string input = "123456";
    std::string expected = "123456";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesSpacesInInput) {
    std::string input = "abc 123 def 456";
    std::string expected = "123 456";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesSpecialCharacters) {
    std::string input = "@123#abc!456";
    std::string expected = "123 456";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesEmptyInput) {
    std::string input = "";
    std::string expected = "";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesLeadingNumbers) {
    std::string input = "123abc";
    std::string expected = "123";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesTrailingNumbers) {
    std::string input = "abc123";
    std::string expected = "123";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesSeparatedNumbers) {
    std::string input = "a1b2c3d4";
    std::string expected = "1 2 3 4";
    EXPECT_EQ(extract_numbers(input), expected);
}

TEST(ExtractNumbersTest, HandlesLongStringWithNumbers) {
    std::string input = "longstringwith1234numbers5678inside";
    std::string expected = "1234 5678";
    EXPECT_EQ(extract_numbers(input), expected);
}
