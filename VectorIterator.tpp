#include "VectorIterator.hpp"
#include <iostream>

template <typename T>
VectorIterator<T>::VectorIterator(T* value):m_value(value){}

template <typename T>
VectorIterator<T>::VectorIterator(const VectorIterator& rhs):m_value(rhs.m_value){}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator=(const VectorIterator& rhs)
{
    m_value = rhs.m_value;
    return *this;
}

template <typename T>
bool VectorIterator<T>::operator!=(const VectorIterator& rhs)
{
    return m_value != rhs.m_value;
}

template <typename T>
bool VectorIterator<T>::operator<(const VectorIterator& rhs)
{
    return m_value < rhs.m_value;
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator++()
{
    ++m_value;
    return *this;
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator--()
{
    --m_value;
    return *this;
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator+=(std::size_t difference)
{
    m_value += difference;
    return *this;
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator-=(std::size_t difference)
{
    m_value -= difference;
    return *this;
}


template <typename T>
VectorIterator<T> VectorIterator<T>::operator+(std::size_t difference)
{
    VectorIterator<T> it;
    it.m_value = m_value + difference;
    return it;
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator-(std::size_t difference)
{
    VectorIterator<T> it;
    it.m_value = m_value - difference;
    return it;
}

template <typename T>
T& VectorIterator<T>::operator*()
{
    return *m_value;
}