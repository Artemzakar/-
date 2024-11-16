#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include "Point.h"
#include <iostream>
#include <cmath>
#include <memory>

template <typename T>
class Triangle : public Figure<T> {
public:
    Triangle() = default;

    Triangle(const Point<T>& first, const Point<T>& second, const Point<T>& third)
        : _first(std::make_unique<Point<T>>(first)),
          _second(std::make_unique<Point<T>>(second)),
          _third(std::make_unique<Point<T>>(third)) {}

    Triangle(const Triangle& other)
        : _first(std::make_unique<Point<T>>(*other._first)),
          _second(std::make_unique<Point<T>>(*other._second)),
          _third(std::make_unique<Point<T>>(*other._third)) {}

    Triangle(Triangle&& other) noexcept = default;

    Triangle& operator=(const Triangle& other) {
        if (this != &other) {
            _first = std::make_unique<Point<T>>(*other._first);
            _second = std::make_unique<Point<T>>(*other._second);
            _third = std::make_unique<Point<T>>(*other._third);
        }
        return *this;
    }

    Triangle& operator=(Triangle&& other) noexcept = default;

    Point<T> geometricCenter() const override {
        T centerX = (_first->getX() + _second->getX() + _third->getX()) / 3;
        T centerY = (_first->getY() + _second->getY() + _third->getY()) / 3;
        return Point<T>(centerX, centerY);
    }

    void print(std::ostream& os) const override {
    os << "{\n"
       << "  \"type\": \"Triangle\",\n"
       << "  \"vertices\": [\n"
       << "    {\"x\": " << _first->getX() << ", \"y\": " << _first->getY() << "},\n"
       << "    {\"x\": " << _second->getX() << ", \"y\": " << _second->getY() << "},\n"
       << "    {\"x\": " << _third->getX() << ", \"y\": " << _third->getY() << "}\n"
       << "  ],\n"
       << "  \"area\": " << static_cast<double>(*this) << "\n"
       << "}";
    }


    void read(std::istream& is) override {
        T x1, y1, x2, y2, x3, y3;
        is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        _first = std::make_unique<Point<T>>(x1, y1);
        _second = std::make_unique<Point<T>>(x2, y2);
        _third = std::make_unique<Point<T>>(x3, y3);
    }

    operator double() const override {
        T x1 = _first->getX(), y1 = _first->getY();
        T x2 = _second->getX(), y2 = _second->getY();
        T x3 = _third->getX(), y3 = _third->getY();
        return std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    }

    bool operator==(const Figure<T>& other) const override {
        const auto* otherTriangle = dynamic_cast<const Triangle<T>*>(&other);
        return otherTriangle &&
               *_first == *otherTriangle->_first &&
               *_second == *otherTriangle->_second &&
               *_third == *otherTriangle->_third;
    }

    std::unique_ptr<Figure<T>> Clone() const override {
        return std::make_unique<Triangle<T>>(*_first, *_second, *_third);
    }

private:
    std::unique_ptr<Point<T>> _first, _second, _third;
};

#endif
