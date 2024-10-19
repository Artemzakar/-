#include "../include/Rectangle.h"

Rectangle::Rectangle(const std::pair<double, double>& center, double width, double height)
    : center(center), width(width), height(height) {}

Rectangle::Rectangle(const Rectangle& other)
    : center(other.center), width(other.width), height(other.height) {}

std::pair<double, double> Rectangle::geometricCenter() const {
    return center;
}

void Rectangle::print(std::ostream& out) const {
    out << "Rectangle center: (" << center.first << ", " << center.second << "), width: " << width << ", height: " << height;
}

void Rectangle::read(std::istream& in) {
    in >> center.first >> center.second >> width >> height;
}

double Rectangle::area() const {
    return width * height;
}

Figure& Rectangle::operator=(const Figure& other) {
    if (this == &other) {
        return *this; 
    }
    
    const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
    if (otherRectangle) {
        center = otherRectangle->center;
        width = otherRectangle->width;
        height = otherRectangle->height;
    }
    return *this;
}

Figure& Rectangle::operator=(Figure&& other) {
    if (this != &other) {
        // Приведение типа для доступа к полям производного класса
        Rectangle& otherRectangle = dynamic_cast<Rectangle&>(other);
        center = std::move(otherRectangle.center); 
        width = otherRectangle.width; 
        height = otherRectangle.height; 
    }
    return *this;
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
    return otherRectangle && center == otherRectangle->center && width == otherRectangle->width && height == otherRectangle->height;
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this); 
}

