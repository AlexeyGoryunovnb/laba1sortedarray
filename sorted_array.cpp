#include "sorted_array.h"
template <class T>
sorted_array<T>::sorted_array(size_t capacity)
    : m_capacity(capacity), m_size(0), m_data(new T[m_capacity]) {}

template <class T>
void sorted_array<T>::push(const T& value) {
    if (m_size == m_capacity) {
        throw std::out_of_range("Array is full");
    }

    size_t index = 0;
    while (index < m_size && m_data[index] < value) {
        ++index;
    }
    shiftRight(index);
    m_data[index] = value;
    ++m_size;
}

template <class T>
size_t sorted_array<T>::size() const {
    return m_size;
}

template <class T>
const T& sorted_array<T>::operator[](size_t index) const {
    return m_data[index];
}

template <class T>
T& sorted_array<T>::operator[](size_t index) {
    return m_data[index];
}

template <class T>
const T& sorted_array<T>::at(size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index is out of range");
    }
    return m_data[index];
}

template <class T>
T& sorted_array<T>::at(size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index is out of range");
    }
    return m_data[index];
}

template <class T>
void sorted_array<T>::erase(size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index is out of range");
    }
    shiftLeft(index);
    --m_size;
}

template <class T>
void sorted_array<T>::shiftRight(size_t index) {
    for (size_t i = m_size; i > index; --i) {
        m_data[i] = m_data[i - 1];
    }
}

template <class T>
void sorted_array<T>::shiftLeft(size_t index) {
    for (size_t i = index; i < m_size - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
}