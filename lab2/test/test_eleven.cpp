#include "gtest/gtest.h"
#include "../include/Eleven.h"

// Тест на конструктор по умолчанию
TEST(ElevenTest, DefaultConstructor) {
    Eleven num;
    EXPECT_EQ(num.size(), 1);
    EXPECT_EQ(num, Eleven("0"));
}

// Тест на конструктор от строки
TEST(ElevenTest, ConstructorFromString) {
    Eleven num("A10");
    EXPECT_EQ(num.size(), 3);
    EXPECT_EQ(num, Eleven("A10"));
}

// Тест на сложение
TEST(ElevenTest, Addition) {
    Eleven num1("A10");
    Eleven num2("1");
    Eleven result = num1 + num2;
    EXPECT_EQ(result, Eleven("A11"));
}

// Тест на вычитание
TEST(ElevenTest, Subtraction) {
    Eleven num1("A11");
    Eleven num2("1");
    Eleven result = num1 - num2;
    EXPECT_EQ(result, Eleven("A10"));
}

// Тест на операторы присваивания
TEST(ElevenTest, AssignmentOperator) {
    Eleven num1("A11");
    Eleven num2;
    num2 = num1;
    EXPECT_EQ(num1, num2);
}

// Тест на операторы присваивания с перемещением
TEST(ElevenTest, MoveAssignmentOperator) {
    Eleven num1("A11");
    Eleven num2 = std::move(num1);
    EXPECT_EQ(num2, Eleven("A11"));
}

// Тест на оператор сравнения
TEST(ElevenTest, ComparisonOperators) {
    Eleven num1("A11");
    Eleven num2("A10");
    EXPECT_TRUE(num1 > num2);
    EXPECT_TRUE(num2 < num1);
    EXPECT_TRUE(num1 >= num2);
    EXPECT_TRUE(num2 <= num1);
    EXPECT_FALSE(num1 == num2);
    EXPECT_TRUE(num1 != num2);
}

// Тест на исключение при вычитании
TEST(ElevenTest, SubtractionUnderflow) {
    Eleven num1("1");
    Eleven num2("A10");
    EXPECT_THROW(num1 - num2, std::underflow_error);
}