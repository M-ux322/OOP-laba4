#pragma once
#include "Polygon.h"
#include "Array.h"
#include <iostream>
#include <memory>
#include <vector>

template<Scalar T>
std::unique_ptr<Figure<T>> input_polygon() {
    int n;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    if (n < 3) {
        std::cout << "Error: at least 3 vertices required.\n";
        return nullptr;
    }

    std::vector<Point<T>> verts;
    verts.reserve(n);
    std::cout << "Enter " << n << " vertices (x y): ";
    for (int i = 0; i < n; ++i) {
        T x, y;
        std::cin >> x >> y;
        verts.emplace_back(x, y);
    }

    return std::make_unique<Polygon<T>>(verts);
}

template<Scalar T>
void print_figures_info(const Array<std::unique_ptr<Figure<T>>>& figures) {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i+1 << ":\n";
        std::cout << "  Center: " << figures[i]->geom_center() << "\n";
        figures[i]->print_vert();
        std::cout << "  Area: " << figures[i]->area() << "\n\n";
    }
}

template<Scalar T>
double total_area(const Array<std::unique_ptr<Figure<T>>>& figures) {
    double sum = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        sum += figures[i]->area();
    }
    return sum;
}