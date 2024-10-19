#include <gtest/gtest.h>
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/FigureArray.h"

// Тест для треугольника
TEST(TriangleTest, AreaTest) {
    Triangle t1({std::array<std::pair<double, double>, 3>{{{0, 0}, {1, 0}, {0, 1}}}});
    EXPECT_DOUBLE_EQ(t1.area(), 0.5);
}

TEST(TriangleTest, CenterTest) {
    Triangle t1({std::array<std::pair<double, double>, 3>{{{0, 0}, {1, 0}, {0, 1}}}});
    auto center = t1.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0 / 3);
    EXPECT_DOUBLE_EQ(center.second, 1.0 / 3);
}

// Тест для квадрата
TEST(SquareTest, AreaTest) {
    Square s1({{0, 0}, 2});
    EXPECT_DOUBLE_EQ(static_cast<double>(s1), 4.0);
}

TEST(SquareTest, CenterTest) {
    Square s1({{0, 0}, 2});
    auto center = s1.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 0);
    EXPECT_DOUBLE_EQ(center.second, 0);
}

// Тест для прямоугольника
TEST(RectangleTest, AreaTest) {
    Rectangle r1({{0, 0}, 2, 3});
    EXPECT_DOUBLE_EQ(static_cast<double>(r1), 6.0);
}

TEST(RectangleTest, CenterTest) {
    Rectangle r1({{0, 0}, 2, 3});
    auto center = r1.geometricCenter();
    EXPECT_DOUBLE_EQ(center.first, 0);
    EXPECT_DOUBLE_EQ(center.second, 0);
}

// Тест для контейнера фигур
TEST(FigureArrayTest, TotalAreaTest) {
    FigureArray array;
    
    Triangle t1({std::array<std::pair<double, double>, 3>{{{0, 0}, {1, 0}, {0, 1}}}});
    Square s1({{0, 0}, 2});
    Rectangle r1({{0, 0}, 2, 3});
    
    array.addFigure(t1.clone()); 
    array.addFigure(s1.clone());  
    array.addFigure(r1.clone());  

    EXPECT_DOUBLE_EQ(array.totalArea(), 0.5 + 4.0 + 6.0); // 0.5 + 4 + 6 = 10.5
}

TEST(FigureArrayTest, RemoveFigureTest) {
    FigureArray array;
    
    Triangle t1({std::array<std::pair<double, double>, 3>{{{0, 0}, {1, 0}, {0, 1}}}});
    Square s1({{0, 0}, 2});
    Rectangle r1({{0, 0}, 2, 3});
    
    array.addFigure(t1.clone()); 
    array.addFigure(s1.clone());  
    array.addFigure(r1.clone());  
    
    array.removeFigure(1); // Удаляем квадрат

    EXPECT_DOUBLE_EQ(array.totalArea(), 0.5 + 6.0); // Оставшиеся фигуры: 0.5 (треугольник) и 6 (прямоугольник)
}

// Тест для вывода треугольника
TEST(TriangleTest, OutputTest) {
    Triangle t1({{{0, 0}, {1, 0}, {0, 1}}});
    std::ostringstream oss;
    t1.print(oss); 
    EXPECT_EQ(oss.str(), "Triangle vertices: (0, 0) (1, 0) (0, 1) "); 
}

// Тест для вывода квадрата
TEST(SquareTest, OutputTest) {
    Square s1({{0, 0}, 2});
    std::ostringstream oss;
    s1.print(oss); 
    EXPECT_EQ(oss.str(), "Square center: (0, 0), side length: 2"); 
}

// Тест для вывода прямоугольника
TEST(RectangleTest, OutputTest) {
    Rectangle r1({{0, 0}, 2, 3});
    std::ostringstream oss;
    r1.print(oss); 
    EXPECT_EQ(oss.str(), "Rectangle center: (0, 0), width: 2, height: 3"); 
}

// Тест для вывода массива фигур
TEST(FigureArrayTest, PrintFiguresTest) {
    FigureArray array;

    Triangle t1({{{0, 0}, {1, 0}, {0, 1}}});
    Square s1({{0, 0}, 2});
    Rectangle r1({{0, 0}, 2, 3});

    array.addFigure(t1.clone());
    array.addFigure(s1.clone());
    array.addFigure(r1.clone());

    std::ostringstream oss;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf()); // Перенаправляем вывод

    array.printFigures(); 

    std::cout.rdbuf(oldCoutBuffer); // Возвращаем стандартный поток

    std::string expectedOutput =
        "Triangle vertices: (0, 0) (1, 0) (0, 1) \n"
        "Площадь: 0.5\n"
        "Геометрический центр: (0.333333, 0.333333)\n\n"
        "Square center: (0, 0), side length: 2\n"
        "Площадь: 4\n"
        "Геометрический центр: (0, 0)\n\n"
        "Rectangle center: (0, 0), width: 2, height: 3\n"
        "Площадь: 6\n"
        "Геометрический центр: (0, 0)\n\n";

    EXPECT_EQ(oss.str(), expectedOutput);
}