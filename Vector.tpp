#include "Vector.hpp"
#include <string.h>
#include <iostream>
contexpr std::size_t INITIAL_CAPACITY = 10;

template <typename T>
Vector<T>::Vector()
{
    m_capacity = INITIAL_CAPACITY;
    m_size = 0;
    m_data = new T[INITIAL_CAPACITY];
}

template <typename T>
Vector<T>::Vector(const Vector& rhs)
{
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    m_data = new T[m_capacity];
    std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);
}

template<typename T>
Vector<T>::Vector(Vector&& rhs)
{
    m_data = rhs.m_data;
    rhs.m_data = nullptr;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] this->m_data;
    m_data = nullptr;
}

template <typename T>
const T& Vector<T>::operator[](std::size_t idx) const
{
    return m_data[idx];
}

template <typename T>
T& Vector<T>::operator[](std::size_t idx)
{
    return m_data[idx];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    if (m_capacity < rhs.m_capacity)
    {
        delete[] m_data;
        m_data = new T[rhs.m_capacity];
    }
    m_capacity = rhs.m_capacity;
    std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_capacity * sizeof(T));
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& rhs)
{
    m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;
    m_data = rhs.m_data;

    rhs.m_data = nullptr;
    rhs.m_capacity = rhs.m_size = 0;
    
    return *this;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec)
{
    for (std::size_t idx = 0; idx < vec.m_size; ++idx)
    {
        os << vec.m_data[idx] << " ";
    }
    os << std::endl;
    return os;
}

template <typename T>
size_t Vector<T>::getSize()
{
    return this->m_size;
}

template <typename T>
size_t Vector<T>::getCapacity()
{
    return this->m_capacity;
}

template <typename T>
void Vector<T>::insert(TIterator pos, T& element)
{
    if (this->m_capacity <= this->m_size)
    {
        reserve((1+m_capacity)*2);
    }
    ++m_size;
   
    for(TIterator it = end() - 1; it != pos; --it)
    {
        *it = *(it - 1) ; 
    }
    *pos = element;
}

template <typename T>
void Vector<T>::insert(TIterator pos, T&& element)
{
    if (this->m_capacity <= this->m_size)
    {
        reserve((1+m_capacity)*2);
    }
    ++m_size;
   
    for(TIterator it = end() - 1; it != pos; --it)
    {
        *it = *(it - 1) ; 
    }
    *pos = std::move(element);
}

template <typename T>
void Vector<T>::pushFront(T& element)
{
    insert(begin(),element);
}

template <typename T>
void Vector<T>::pushFront(T&& element)
{
    insert(begin(),element);
}

template <typename T>
void Vector<T>::pushBack(T& element)
{
    //insert(end(), element);
    m_data[m_size++] = element;

}

template <typename T>
void Vector<T>::pushBack(T&& element)
{
    //insert(end(), std::move(element));
    m_data[m_size++] = std::move(element);
}

template <typename T>
void Vector<T>::erase(TIterator pos)
{
    for(TIterator it = pos; it != end() - 1; ++it)
    {
        *it = *(it + 1);
    }
    --m_size;
}

template <typename T>
void Vector<T>::popFront()
{
    erase(begin());
}

template <typename T>
void Vector<T>::popBack()
{
    erase(end() - 1);
}

template <typename T>
T Vector<T>::getFront()
{
    return this->m_data[0];
}

template <typename T>
T Vector<T>::getBack()
{
    return this->m_data[this->m_size - 1];
}

template <typename T>
void Vector<T>::setFront(T element)
{
    this->m_data[0] = element;
}

template <typename T>
void Vector<T>::setBack(T element)
{
    this->m_data[this->m_size] = element;
}

template <typename T>
void Vector<T>::clear()
{
    m_size = 0;
}

template <typename T>
bool Vector<T>::empty()
{
    return m_size = 0;
}

template <typename T>
void Vector<T>::reserve(size_t newCapacity)
{
    if (this->m_capacity < newCapacity)
    {
        T* newData = new T[newCapacity];
        this->m_capacity = newCapacity;

        for (size_t i = 0; i < this->m_size; ++i)
        {
            newData[i] = this->m_data[i];
        }
        delete[] this->m_data;
        this->m_data = newData;
    }
}

template <typename T>
void Vector<T>::resize(std::size_t newSize)
{
    if(newSize < 0) return;
    if(newSize <= m_capacity)
    {
        for(std::size_t idx = m_size; idx < newSize; ++idx)
        {
            m_data[idx] = T();
        }

    }
    else
    {
        reserve((m_capacity + 1) * 2);
    }
    m_size = newSize;
}

template <typename T>
VectorIterator<T> Vector<T>::begin()
{
    return VectorIterator<T>(m_data);
}

template <typename T>
VectorIterator<T> Vector<T>::end()
{
    return VectorIterator<T>(m_data + m_size);
}

template <typename T>
void Vector<T>::print()
{
    for (size_t i = 0; i < this->m_size; ++i)
    std::cout << m_data[i] << " ";
}
