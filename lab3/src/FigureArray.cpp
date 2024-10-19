#include "../include/FigureArray.h"

FigureArray::~FigureArray() {
    for (auto figure : figures) {
        delete figure;
    }
}

void FigureArray::addFigure(Figure* figure) {
    figures.push_back(figure->clone()); // Используем метод clone для добавления копии
}

void FigureArray::removeFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }
}

double FigureArray::totalArea() const {
    double total = 0;
    for (const auto& figure : figures) {
        total += static_cast<double>(*figure);
    }
    return total;
}

void FigureArray::printFigures() const {
    for (const auto& figure : figures) {
        std::cout << *figure << "\n";
        std::cout << "Площадь: " << static_cast<double>(*figure) << "\n";
        std::cout << "Геометрический центр: (" << figure->geometricCenter().first << ", " 
                  << figure->geometricCenter().second << ")\n\n";
    }
}
