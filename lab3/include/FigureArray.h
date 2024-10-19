#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H

#include "Figure.h"
#include <vector>

class FigureArray {
private:
    std::vector<Figure*> figures;

public:
    ~FigureArray();
    
    void addFigure(Figure* figure);
    void removeFigure(int index);
    double totalArea() const;
    void printFigures() const;
};

#endif
