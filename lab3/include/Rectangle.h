// #ifndef RECTANGLE_H
// #define RECTANGLE_H

// #include "Figure.h"
// #include <utility>

// class Rectangle : public Figure {
// public:
//     Rectangle(const std::pair<double, double>& center, double width, double height);

//     std::pair<double, double> geometricCenter() const;
//     void print(std::ostream& out) const;
//     void read(std::istream& in);
//     double area() const;

//     Figure& operator=(const Figure& other);
//     Figure& operator=(Figure&& other);
//     bool operator==(const Figure& other) const;

// private:
//     std::pair<double, double> center;
//     double width;
//     double height;
// };

// #endif

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include <utility>

class Rectangle : public Figure {
public:
    Rectangle(const std::pair<double, double>& center, double width, double height);
    Rectangle(const Rectangle& other);

    std::pair<double, double> geometricCenter() const override;
    void print(std::ostream& out) const override;
    void read(std::istream& in) override;
    double area() const override;

    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) override;
    bool operator==(const Figure& other) const override;
    Figure* clone() const override;

private:
    std::pair<double, double> center;
    double width;
    double height;
};

#endif
