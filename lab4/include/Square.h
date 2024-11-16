#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"
#include "Point.h"
#include <iostream>
#include <memory>

template<typename T>
class Square : public Figure<T> {
public:
    Square() : side(0) {}
    Square(const Point<T>& center, T side)
        : centerPoint(std::make_unique<Point<T>>(center)), side(side) {}

    Square(const Square& other)
        : centerPoint(std::make_unique<Point<T>>(*other.centerPoint)), side(other.side) {}

    Square(Square&& other) noexcept
        : centerPoint(std::move(other.centerPoint)), side(other.side) {
        other.side = 0;
    }

    Square& operator=(const Square& other) {
        if (this != &other) {
            centerPoint = std::make_unique<Point<T>>(*other.centerPoint);
            side = other.side;
        }
        return *this;
    }

    Square& operator=(Square&& other) noexcept {
        if (this != &other) {
            centerPoint = std::move(other.centerPoint);
            side = other.side;
            other.side = 0;
        }
        return *this;
    }

    Point<T> geometricCenter() const override {
        return *centerPoint;
    }

    void print(std::ostream& os) const override {
        os << "{\n"
           << "  \"type\": \"Square\",\n"
           << "  \"center\": {\"x\": " << centerPoint->getX() << ", \"y\": " << centerPoint->getY() << "},\n"
           << "  \"side\": " << side << ",\n"
           << "  \"area\": " << static_cast<double>(*this) << "\n"
           << "}";
    }

    void read(std::istream& is) override {
        T x, y;
        is >> x >> y >> side;
        *centerPoint = Point<T>(x, y);
    }

    operator double() const override {
        return static_cast<double>(side) * side;
    }

    bool operator==(const Figure<T>& other) const override {
        const auto* otherSquare = dynamic_cast<const Square*>(&other);
        return otherSquare && *centerPoint == *otherSquare->centerPoint && side == otherSquare->side;
    }

    std::unique_ptr<Figure<T>> Clone() const override {
        return std::make_unique<Square<T>>(*centerPoint, side);
    }

private:
    std::unique_ptr<Point<T>> centerPoint;
    T side;
};

#endif
