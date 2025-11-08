#pragma once
#include "Figure.h"
#include <vector>

template<Scalar T>
class Polygon : public Figure<T> {
private:
    std::vector<Point<T>> vertices_;
    
public:
    Polygon();
    Polygon(const std::vector<Point<T>>& vertices);
    Polygon(std::initializer_list<Point<T>> verts);

    Point<T> geom_center() const override;
    double area() const override;
    void print_vert() const override;
    std::unique_ptr<Figure<T>> copy() const override;
    
    bool operator==(const Figure<T>& other) const override;
};