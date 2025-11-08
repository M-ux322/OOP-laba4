#include "Polygon.h"
#include <cmath>
#include <iostream>

template<Scalar T>
Polygon<T>::Polygon() {}
template<Scalar T>

Polygon<T>::Polygon(const std::vector<Point<T>>& vertices) : vertices_(vertices) {
    if (vertices.size() < 3) throw "At least 3 vertices required";
}
template<Scalar T>
Polygon<T>::Polygon(std::initializer_list<Point<T>> verts) : vertices_(verts) {
    if (verts.size() < 3) throw "At least 3 vertices required";
}
template<Scalar T>
Point<T> Polygon<T>::geom_center() const {
    T sum_x = 0, sum_y = 0;
    for (const auto& p : vertices_) {
        sum_x += p.x();
        sum_y += p.y();
    }
    return Point<T>(sum_x / vertices_.size(), sum_y / vertices_.size());
}
template<Scalar T>
double Polygon<T>::area() const {
    if (vertices_.size() < 3) return 0.0;
    
    double sum1 = 0.0, sum2 = 0.0;
    for (size_t i = 0; i < vertices_.size(); ++i) {
        size_t j = (i + 1) % vertices_.size();
        sum1 += vertices_[i].x() * vertices_[j].y();
        sum2 += vertices_[j].x() * vertices_[i].y();
    }
    return std::abs(sum1 - sum2) / 2.0;
}
template<Scalar T>
void Polygon<T>::print_vert() const {
    std::cout << "Polygon vertices: ";
    for (size_t i = 0; i < vertices_.size(); ++i) {
        std::cout << vertices_[i];
        if (i + 1 < vertices_.size()) std::cout << ", ";
    }
    std::cout << std::endl;
}
template<Scalar T>
std::unique_ptr<Figure<T>> Polygon<T>::copy() const {
    return std::make_unique<Polygon<T>>(*this);
}
template<Scalar T>
bool Polygon<T>::operator==(const Figure<T>& other) const {
    auto* p = dynamic_cast<const Polygon<T>*>(&other);
    return p && vertices_ == p->vertices_;
}
template class Polygon<double>;
