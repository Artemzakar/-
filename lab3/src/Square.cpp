#include "../include/Square.h"

Square::Square(const std::pair<double, double>& center, double sideLength)
    : center(center), sideLength(sideLength) {}

Square::Square(const Square& other) 
        : center(other.center), sideLength(other.sideLength) {}

std::pair<double, double> Square::geometricCenter() const {
    return center;
}

void Square::print(std::ostream& out) const {
    out << "Square center: (" << center.first << ", " << center.second << "), side length: " << sideLength;
}

void Square::read(std::istream& in) {
    in >> center.first >> center.second >> sideLength;
}

double Square::area() const {
    return sideLength * sideLength;
}

Figure& Square::operator=(const Figure& other) {
    if (this == &other) {
        return *this;
    }
    
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (otherSquare) {
        center = otherSquare->center;
        sideLength = otherSquare->sideLength;
    }
    return *this;
}

Figure& Square::operator=(Figure&& other) {
    if (this != &other) {
        // Приведение типа для доступа к полям производного класса
        Square& otherSquare = dynamic_cast<Square&>(other);
        center = std::move(otherSquare.center); 
        sideLength = otherSquare.sideLength; 
    }
    return *this;
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    return otherSquare && center == otherSquare->center && sideLength == otherSquare->sideLength;
}

Figure* Square::clone() const {
    return new Square(center, sideLength); 
}


