// #ifndef SQUARE_H
// #define SQUARE_H

// #include "Figure.h"
// #include <utility>

// class Square : public Figure {
// public:
//     Square(const std::pair<double, double>& center, double sideLength);

//     std::pair<double, double> geometricCenter() const;
//     void print(std::ostream& out) const;
//     void read(std::istream& in);
//     double area() const;

//     Figure& operator=(const Figure& other);
//     Figure& operator=(Figure&& other);
//     bool operator==(const Figure& other) const;

// private:
//     std::pair<double, double> center;
//     double sideLength;
// };

// #endif


#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"
#include <utility>

class Square : public Figure {
public:
    Square(const std::pair<double, double>& center, double sideLength);
    Square(const Square& other);

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
    double sideLength;
};

#endif

