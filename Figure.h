#pragma once
#include "Point.h"
#include <memory>

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Point<T> geom_center() const = 0;
    virtual double area() const = 0;
    virtual void print_vert() const = 0;
    virtual std::unique_ptr<Figure<T>> copy() const = 0;
    operator double() const { return area(); }
    virtual bool operator==(const Figure<T>& other) const = 0;
};
