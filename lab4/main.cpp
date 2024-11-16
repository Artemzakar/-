#include <iostream>
#include <memory>
#include "include/FigureArray.h"
#include "include/Square.h"
#include "include/Rectangle.h"
#include "include/Triangle.h"

int main() {
    try {
        // Создание массива для базового типа Figure<int>*
        FigureArray<Figure<int>*> figureArray(2);

        auto square = new Square<int>(Point<int>(0, 0), 4); // Площадь = 16
        auto rectangle = new Rectangle<int>(Point<int>(1, 1), 5, 3); // Площадь = 15
        auto triangle = new Triangle<int>(Point<int>(0, 0), Point<int>(3, 0), Point<int>(0, 2)); // Площадь = 3

        // Добавление фигур в массив
        figureArray.append(square);
        figureArray.append(rectangle);
        figureArray.append(triangle);

        std::cout << "Содержимое массива (координаты фигур):\n";
        figureArray.printCoordinates(std::cout);

        std::cout << "\nОбщая площадь фигур в массиве: " << figureArray.getTotalArea() << "\n";

        // Удаление элемента
        figureArray.remove(1);
        std::cout << "\nПосле удаления элемента:\n";
        figureArray.printCoordinates(std::cout);
        std::cout << "Общая площадь: " << figureArray.getTotalArea() << "\n";

        // Создание массива для наследника Square<int>
        FigureArray<Square<int>> squareArray(2);
        Square<int> square1(Point<int>(0, 0), 4); // Площадь = 16
        Square<int> square2(Point<int>(1, 1), 3); // Площадь = 9

        squareArray.append(square1);
        squareArray.append(square2);

        std::cout << "\nСодержимое массива Square<int>:\n";
        squareArray.printCoordinates(std::cout);

        std::cout << "\nОбщая площадь квадратов: " << squareArray.getTotalArea() << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}
