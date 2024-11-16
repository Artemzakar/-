#ifndef FIGURE_H
#define FIGURE_H

#include <memory>
#include <iostream>
#include "Point.h"

template <typename T>
class Figure {
    public:
        using scalar_type = T;
        virtual ~Figure() = default;

        virtual Point<T> geometricCenter() const = 0; 
        virtual void print(std::ostream& os) const = 0;
        virtual void read(std::istream& in) = 0; 
        virtual operator double() const = 0;
        virtual bool operator==(const Figure<T>& other) const = 0;
        virtual std::unique_ptr<Figure<T>> Clone() const = 0;

        friend std::istream& operator>>(std::istream& in, Figure<T>& figure) { 
            return figure.read(in);
        }

        friend std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
            return figure.print(os);
        }
};

#endif
