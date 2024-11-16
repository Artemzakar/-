#ifndef POINT_H
#define POINT_H

#include <concepts>
#include <iostream>
#include <cmath>
#include <type_traits>

template<typename T>
concept Scalar = std::is_arithmetic_v<T>;

template<Scalar T>
class Point {
public:
    T x, y;

    // Конструкторы
    Point() : x(0), y(0) {}
    Point(T xValue, T yValue) : x(xValue), y(yValue) {}
    Point(const Point& other) : x(other.x), y(other.y) {}
    Point(Point&& other) noexcept : x(std::move(other.x)), y(std::move(other.y)) {}

    // Методы доступа
    T getX() const { return x; }
    T getY() const { return y; }

    // Вычисление расстояния между точками
    double distanceTo(const Point& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    // Оператор сравнения
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // Операторы присваивания
    Point& operator=(const Point& other) {
        if (this == &other) {
            return *this; // Проверка на самоприсваивание
        }
        x = other.x;
        y = other.y;
        return *this;
    }

    Point& operator=(Point&& other) noexcept {
        if (this == &other) {
            return *this; // Проверка на самоприсваивание
        }
        x = std::move(other.x);
        y = std::move(other.y);
        return *this;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << '(' << point.x << ", " << point.y << ')';
        return os;
    }

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& in, Point& point) {
        in >> point.x >> point.y;
        if (in.fail()) {
            throw std::invalid_argument("Ошибка ввода координат точки. Ожидаются два скалярных значения.");
        }
        return in;
    }
};

#endif // POINT_H
