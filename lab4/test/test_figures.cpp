#include <gtest/gtest.h>
#include "../include/FigureArray.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/Triangle.h"

// Тест на проверку добавления и получения элементов
TEST(FigureArrayTest, TestAppendAndGet) {
    auto square = new Square<int>(Point<int>(0, 0), 4);
    auto rectangle = new Rectangle<int>(Point<int>(0, 0), 5, 3);
    auto triangle = new Triangle<int>(
        Point<int>(0, 0), Point<int>(3, 0), Point<int>(1, 2));

    FigureArray<Figure<int>*> array(2);

    array.append(square);
    EXPECT_EQ(array.get(0), square);

    array.append(rectangle);
    EXPECT_EQ(array.get(1), rectangle);

    array.append(triangle);
    EXPECT_EQ(array.get(2), triangle);
}

// Тест на проверку удаления элемента
TEST(FigureArrayTest, TestRemove) {
    auto square = new Square<int>(Point<int>(0, 0), 4);
    auto rectangle = new Rectangle<int>(Point<int>(0, 0), 5, 3);

    FigureArray<Figure<int>*> array(2);
    array.append(square);
    array.append(rectangle);

    array.remove(0);
    EXPECT_EQ(array.size(), 1);
    EXPECT_EQ(array.get(0), rectangle);

    array.remove(0);
    EXPECT_EQ(array.size(), 0);
}

// Тест на проверку общей площади
TEST(FigureArrayTest, TestGetTotalArea) {
    auto square = new Square<int>(Point<int>(0, 0), 4);   // Площадь = 16
    auto rectangle = new Rectangle<int>(Point<int>(0, 0), 5, 3); // Площадь = 15

    FigureArray<Figure<int>*> array(2);
    array.append(square);
    array.append(rectangle);

    double expectedArea = 16.0 + 15.0;
    EXPECT_DOUBLE_EQ(array.getTotalArea(), expectedArea);
}

// Тест на проверку изменения элемента
TEST(FigureArrayTest, TestSet) {
    auto square1 = new Square<int>(Point<int>(0, 0), 4);
    auto square2 = new Square<int>(Point<int>(0, 0), 2);

    FigureArray<Figure<int>*> array(2);
    array.append(square1);

    EXPECT_EQ(array.get(0), square1);

    array.set(0, square2);
    EXPECT_EQ(array.get(0), square2);
}

// Тест на проверку исключения при доступе к несуществующему индексу
TEST(FigureArrayTest, TestOutOfRangeException) {
    auto square = new Square<int>(Point<int>(0, 0), 4);
    FigureArray<Figure<int>*> array(1);

    array.append(square);

    EXPECT_THROW(array.get(1), std::out_of_range);
    EXPECT_THROW(array.set(1, square), std::out_of_range);
    EXPECT_THROW(array.remove(1), std::out_of_range);
}

// Тест на проверку динамического увеличения массива
TEST(FigureArrayTest, TestResize) {
    auto square = new Square<int>(Point<int>(0, 0), 4);
    auto rectangle = new Rectangle<int>(Point<int>(0, 0), 5, 3);
    auto triangle = new Triangle<int>(
        Point<int>(0, 0), Point<int>(3, 0), Point<int>(1, 2));

    FigureArray<Figure<int>*> array(2);

    array.append(square);
    array.append(rectangle);

    EXPECT_EQ(array.size(), 2);

    array.append(triangle); 
    EXPECT_EQ(array.size(), 3);

    EXPECT_EQ(array.get(0), square);
    EXPECT_EQ(array.get(1), rectangle);
    EXPECT_EQ(array.get(2), triangle);
}

// Тест на проверку печати координат фигур
TEST(FigureArrayTest, TestPrintCoordinates) {
    auto square = new Square<int>(Point<int>(0, 0), 4);
    auto rectangle = new Rectangle<int>(Point<int>(0, 0), 5, 3);

    FigureArray<Figure<int>*> array(2);
    array.append(square);
    array.append(rectangle);

    std::ostringstream output;
    array.printCoordinates(output);

    std::string expectedOutput = 
        "{\n"
        "  \"type\": \"Square\",\n"
        "  \"center\": {\"x\": 0, \"y\": 0},\n"
        "  \"side\": 4,\n"
        "  \"area\": 16\n"
        "}\n"
        "{\n"
        "  \"type\": \"Rectangle\",\n"
        "  \"center\": {\"x\": 0, \"y\": 0},\n"
        "  \"width\": 5,\n"
        "  \"height\": 3,\n"
        "  \"area\": 15\n"
        "}\n";

    EXPECT_EQ(output.str(), expectedOutput);
}


// Тест на проверку обработки указателей
TEST(FigureArrayTest, TestPointerHandling) {
    auto square = new Square<int>(Point<int>(0, 0), 4);

    FigureArray<Figure<int>*> array(1);
    array.append(square);

    EXPECT_EQ(array.get(0), square);

    array.remove(0);
    EXPECT_EQ(array.size(), 0);
}

// Тест на работу с массивом Square<int>
TEST(FigureArrayTest, TestSquareArray) {
    Square<int> square1(Point<int>(0, 0), 4);  // Площадь = 16
    Square<int> square2(Point<int>(1, 1), 2); // Площадь = 4

    FigureArray<Square<int>> array(2);
    array.append(square1);
    array.append(square2);

    // Проверяем размер массива
    EXPECT_EQ(array.size(), 2);

    // Проверяем правильность площадей
    EXPECT_EQ(static_cast<double>(array.get(0)), 16.0);
    EXPECT_EQ(static_cast<double>(array.get(1)), 4.0);

    // Проверяем удаление элемента
    array.remove(0);
    EXPECT_EQ(array.size(), 1);
    EXPECT_EQ(static_cast<double>(array.get(0)), 4.0);
}

// Тест на работу с массивом Rectangle<int>
TEST(FigureArrayTest, TestRectangleArray) {
    Rectangle<int> rectangle1(Point<int>(0, 0), 4, 5);  // Площадь = 20
    Rectangle<int> rectangle2(Point<int>(1, 1), 2, 3); // Площадь = 6

    FigureArray<Rectangle<int>> array(2);
    array.append(rectangle1);
    array.append(rectangle2);

    // Проверяем размер массива
    EXPECT_EQ(array.size(), 2);

    // Проверяем правильность площадей
    EXPECT_EQ(static_cast<double>(array.get(0)), 20.0);
    EXPECT_EQ(static_cast<double>(array.get(1)), 6.0);

    // Проверяем замену элемента
    array.set(0, rectangle2);
    EXPECT_EQ(static_cast<double>(array.get(0)), 6.0);
}

// Тест на работу с массивом Triangle<int>
TEST(FigureArrayTest, TestTriangleArray) {
    Triangle<int> triangle1(Point<int>(0, 0), Point<int>(4, 0), Point<int>(0, 3));  // Площадь = 6
    Triangle<int> triangle2(Point<int>(1, 1), Point<int>(3, 1), Point<int>(1, 4));  // Площадь = 3

    FigureArray<Triangle<int>> array(2);
    array.append(triangle1);
    array.append(triangle2);

    // Проверяем размер массива
    EXPECT_EQ(array.size(), 2);

    // Проверяем правильность площадей
    EXPECT_EQ(static_cast<double>(array.get(0)), 6.0);
    EXPECT_EQ(static_cast<double>(array.get(1)), 3.0);

    // Проверяем удаление элемента
    array.remove(1);
    EXPECT_EQ(array.size(), 1);
    EXPECT_EQ(static_cast<double>(array.get(0)), 6.0);
}
