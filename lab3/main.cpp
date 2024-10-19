#include <iostream>
#include <array>
#include "include/Triangle.h"
#include "include/Square.h"
#include "include/Rectangle.h"
#include "include/FigureArray.h"

int main() {
    // Пример создания объекта Triangle
    Triangle triangle({std::array<std::pair<double, double>, 3>{{{0, 0}, {1, 0}, {0, 1}}}});

    // Пример создания объекта Square
    Square square({{1, 1}, 2.0});

    // Пример создания объекта Rectangle
    Rectangle rectangle({{2, 2}, 3.0, 4.0});

    // Вывод информации о фигурах
    std::cout << "Geometric Center of Triangle: " 
              << triangle.geometricCenter().first << ", " 
              << triangle.geometricCenter().second << std::endl;
    std::cout << "Area of Triangle: " << static_cast<double>(triangle) << std::endl;
    std::cout << triangle << std::endl;

    std::cout << "Geometric Center of Square: " 
              << square.geometricCenter().first << ", " 
              << square.geometricCenter().second << std::endl;
    std::cout << "Area of Square: " << static_cast<double>(square) << std::endl;
    std::cout << square << std::endl;

    std::cout << "Geometric Center of Rectangle: " 
              << rectangle.geometricCenter().first << ", " 
              << rectangle.geometricCenter().second << std::endl;
    std::cout << "Area of Rectangle: " << static_cast<double>(rectangle) << std::endl;
    std::cout << rectangle << std::endl;

    // Пример использования FigureArray
    FigureArray array;
    array.addFigure(triangle.clone()); 
    array.addFigure(square.clone());
    array.addFigure(rectangle.clone());

    std::cout << "Total Area in FigureArray: " << array.totalArea() << std::endl;

    return 0;
}
