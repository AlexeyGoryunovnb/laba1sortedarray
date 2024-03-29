#pragma once

#include <cstddef>
#include <stdexcept>

template <class T>
class sorted_array {
public:
    sorted_array(size_t capacity);
    void push(const T& value);
    size_t size() const;
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    const T& at(size_t index) const;
    T& at(size_t index);
    void erase(size_t index);

private:
    size_t m_capacity;
    size_t m_size;
    T* m_data;

    void shiftRight(size_t index);
    void shiftLeft(size_t index);
};