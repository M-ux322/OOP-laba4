#pragma once
#include <iostream>
#include <concepts>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
private:
    T x_, y_;
public:
    Point() : x_(0), y_(0) {}
    Point(T x, T y) : x_(x), y_(y) {}
    
    T x() const { return x_; }
    T y() const { return y_; }
    
    bool operator==(const Point<T>& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
        os << "(" << point.x_ << ", " << point.y_ << ")";
        return os;
    }
};