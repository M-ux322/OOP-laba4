#pragma once
#include <memory>
#include <cstddef>

template<typename T>
class Array {
private:
    std::unique_ptr<T[]> data_;
    size_t size_;
    size_t capacity_;
    void resize(size_t new_capacity);
public:
    Array();
    explicit Array(size_t initial_capacity);
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;
    ~Array() = default;
    
    void push_back(T&& value);
    void remove(size_t index);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
    size_t capacity() const;
};
