#include "../include/Triangle.h"
#include <cmath>

Triangle::Triangle(const std::array<std::pair<double, double>, 3>& vertices) : vertices(vertices) {}

Triangle::Triangle(const Triangle& other) 
        : vertices(other.vertices) {}

std::pair<double, double> Triangle::geometricCenter() const {
    double x = (vertices[0].first + vertices[1].first + vertices[2].first) / 3.0;
    double y = (vertices[0].second + vertices[1].second + vertices[2].second) / 3.0;
    return {x, y};
}

void Triangle::print(std::ostream& out) const {
    out << "Triangle vertices: ";
    for (const auto& vertex : vertices) {
        out << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Triangle::read(std::istream& in) {
    for (auto& vertex : vertices) {
        in >> vertex.first >> vertex.second;
    }
}

double Triangle::area() const {
    return 0.5 * std::abs(
        vertices[0].first * (vertices[1].second - vertices[2].second) +
        vertices[1].first * (vertices[2].second - vertices[0].second) +
        vertices[2].first * (vertices[0].second - vertices[1].second)
    );
}

Figure& Triangle::operator=(const Figure& other) {
    if (this == &other) {
        return *this; 
    }
    
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (otherTriangle) {
        vertices = otherTriangle->vertices;
    }
    return *this;
}

Figure& Triangle::operator=(Figure&& other) {
    if (this != &other) {
        // Приведение типа для доступа к полям производного класса
        Triangle& otherTriangle = dynamic_cast<Triangle&>(other);
        vertices = std::move(otherTriangle.vertices); 
    }
    return *this;
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    return otherTriangle && vertices == otherTriangle->vertices;
}

Figure* Triangle::clone() const {
    return new Triangle(*this);
}
