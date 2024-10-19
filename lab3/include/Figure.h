#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>

// Абстрактный класс Figure
class Figure {
public:
    virtual ~Figure() = default;

    // Чисто виртуальные функции
    virtual std::pair<double, double> geometricCenter() const = 0;
    virtual void print(std::ostream& out) const = 0;
    virtual void read(std::istream& in) = 0;
    virtual double area() const = 0;

    // Оператор присваивания
    virtual Figure& operator=(const Figure& other) = 0;
    // Оператор перемещения
    virtual Figure& operator=(Figure&& other) = 0;
    // Оператор сравнения
    virtual bool operator==(const Figure& other) const = 0;
    // Создаёт и возвращает копию текущего объекта
    virtual Figure* clone() const = 0;

    // Оператор приведения к double для получения площади
    operator double() const {
        return area();
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const Figure& figure) {
        figure.print(out);
        return out;
    }

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& in, Figure& figure) {
        figure.read(in);
        return in;
    }
};

#endif
