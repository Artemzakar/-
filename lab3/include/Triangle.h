// #ifndef TRIANGLE_H
// #define TRIANGLE_H

// #include "Figure.h"
// #include <array>

// class Triangle : public Figure {
// public:
//     Triangle(const std::array<std::pair<double, double>, 3>& vertices);

//     std::pair<double, double> geometricCenter() const;
//     void print(std::ostream& out) const;
//     void read(std::istream& in);
//     double area() const;

//     Figure& operator=(const Figure& other);
//     Figure& operator=(Figure&& other);
//     bool operator==(const Figure& other) const;

// private:
//     std::array<std::pair<double, double>, 3> vertices;
// };

// #endif

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include <array>

class Triangle : public Figure {
public:
    Triangle(const std::array<std::pair<double, double>, 3>& vertices);
    Triangle(const Triangle& other);

    std::pair<double, double> geometricCenter() const override;
    void print(std::ostream& out) const override;
    void read(std::istream& in) override;
    double area() const override;

    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) override;
    bool operator==(const Figure& other) const override;
    Figure* clone() const override;

private:
    std::array<std::pair<double, double>, 3> vertices;
};

#endif
