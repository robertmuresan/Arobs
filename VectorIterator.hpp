#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP
#include <iostream>

template <typename T>
class VectorIterator{
public:
    VectorIterator(T* value);
    VectorIterator(const VectorIterator& rhs);
    VectorIterator& operator=(const VectorIterator& rhs);

    bool operator!=(const VectorIterator& rhs);
    bool operator<(const VectorIterator& rhs);

    VectorIterator& operator++();
    VectorIterator& operator--();
    VectorIterator& operator+=(std::size_t difference);
    VectorIterator& operator-=(std::size_t difference);
    VectorIterator operator+(std::size_t difference);
    VectorIterator operator-(std::size_t difference);

    T& operator*();

private:
    T* m_value;
};

#include "VectorIterator.tpp"
#endif