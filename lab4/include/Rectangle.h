#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include "Point.h"
#include <iostream>
#include <memory>

template<typename T>
class Rectangle : public Figure<T> {
public:
    Rectangle() : width(0), height(0) {}
    Rectangle(const Point<T>& center, T width, T height)
        : centerPoint(std::make_unique<Point<T>>(center)), width(width), height(height) {}

    Rectangle(const Rectangle& other)
        : centerPoint(std::make_unique<Point<T>>(*other.centerPoint)), width(other.width), height(other.height) {}

    Rectangle(Rectangle&& other) noexcept
        : centerPoint(std::move(other.centerPoint)), width(other.width), height(other.height) {
        other.width = 0;
        other.height = 0;
    }

    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) {
            centerPoint = std::make_unique<Point<T>>(*other.centerPoint);
            width = other.width;
            height = other.height;
        }
        return *this;
    }

    Rectangle& operator=(Rectangle&& other) noexcept {
        if (this != &other) {
            centerPoint = std::move(other.centerPoint);
            width = other.width;
            height = other.height;
            other.width = 0;
            other.height = 0;
        }
        return *this;
    }

    Point<T> geometricCenter() const override {
        return *centerPoint;
    }

    void print(std::ostream& os) const override {
        os << "{\n"
           << "  \"type\": \"Rectangle\",\n"
           << "  \"center\": {\"x\": " << centerPoint->getX() << ", \"y\": " << centerPoint->getY() << "},\n"
           << "  \"width\": " << width << ",\n"
           << "  \"height\": " << height << ",\n"
           << "  \"area\": " << static_cast<double>(*this) << "\n"
           << "}";
    }

    void read(std::istream& is) override {
        T x, y;
        is >> x >> y >> width >> height;
        *centerPoint = Point<T>(x, y);
    }

    operator double() const override {
        return static_cast<double>(width) * height;
    }

    bool operator==(const Figure<T>& other) const override {
        const auto* otherRectangle = dynamic_cast<const Rectangle*>(&other);
        return otherRectangle && *centerPoint == *otherRectangle->centerPoint 
               && width == otherRectangle->width && height == otherRectangle->height;
    }

    std::unique_ptr<Figure<T>> Clone() const override {
        return std::make_unique<Rectangle<T>>(*centerPoint, width, height);
    }

private:
    std::unique_ptr<Point<T>> centerPoint;
    T width;
    T height;
};

#endif
