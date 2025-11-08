#include "Array.h"
#include "Figure.h"
#include <algorithm>

template<typename T>
void Array<T>::resize(size_t new_capacity) {
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = std::move(data_[i]);
    }
    data_ = std::move(new_data);
    capacity_ = new_capacity;
}

template<typename T>
Array<T>::Array() : size_(0), capacity_(10) {
    data_ = std::make_unique<T[]>(capacity_);
}

template<typename T>
Array<T>::Array(size_t initial_capacity) : size_(0), capacity_(initial_capacity) {
    data_ = std::make_unique<T[]>(capacity_);
}

template<typename T>
Array<T>::Array(const Array& other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = std::make_unique<T[]>(capacity_);
    for (size_t i = 0; i < size_; ++i) {
        if constexpr (std::is_same_v<T, std::unique_ptr<Figure<double>>>) {
            data_[i] = other.data_[i] ? other.data_[i]->copy() : nullptr;
        } else {
            data_[i] = other.data_[i];
        }
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = std::make_unique<T[]>(capacity_);
        for (size_t i = 0; i < size_; ++i) {
            if constexpr (std::is_same_v<T, std::unique_ptr<Figure<double>>>) {
                data_[i] = other.data_[i] ? other.data_[i]->copy() : nullptr;
            } else {
                data_[i] = other.data_[i];
            }
        }
    }
    return *this;
}

template<typename T>
Array<T>::Array(Array&& other) noexcept
    : data_(std::move(other.data_)), size_(other.size_), capacity_(other.capacity_) {
    other.size_ = 0;
    other.capacity_ = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        data_ = std::move(other.data_);
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

template<typename T>
void Array<T>::push_back(T&& value) {
    if (size_ >= capacity_) resize(capacity_ * 2);
    data_[size_++] = std::move(value);
}

template<typename T>
void Array<T>::remove(size_t index) {
    if (index >= size_) return;
    for (size_t i = index; i < size_ - 1; ++i) {
        data_[i] = std::move(data_[i + 1]);
    }
    --size_;
}

template<typename T>
T& Array<T>::operator[](size_t index) { return data_[index]; }

template<typename T>
const T& Array<T>::operator[](size_t index) const { return data_[index]; }

template<typename T>
size_t Array<T>::size() const { return size_; }

template<typename T>
size_t Array<T>::capacity() const { return capacity_; }

template class Array<std::unique_ptr<Figure<double>>>;