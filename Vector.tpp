#include "Vector.hpp"
#include <iostream>
#include <string.h>
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
    memcpy(m_data, rhs.m_data, m_capacity * sizeof(T));
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] this->m_data;
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
    if (m_capacity != rhs.m_capacity)
    {
        delete[] m_data;
        m_data = new T[rhs.m_capacity];
    }
    m_capacity = rhs.m_capacity;
    memcpy(m_data, rhs.m_data, m_capacity * sizeof(T));
    return *this;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec)
{
    for (std::size_t idx = 0; idx < vec.m_capacity; ++idx)
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
void Vector<T>::insert(size_t idx, T element)
{
    if (this->m_capacity <= this->m_size)
    {
        reserve((1+m_capacity)*2);
    }

    if (idx >= 0 && idx <= this->m_size)
    {
        for (size_t i = idx; i < this->m_size - 1; ++i)
        {
            this->m_data[i+1] = this->m_data[i];
            this->m_size++;
        }
        this->m_data[idx] = element;
    }
}

template <typename T>
void Vector<T>::pushFront(T element)
{
    if (this->m_capacity <= this->m_size)
    {
        reserve((1+m_capacity) * 2);
    }

    for (size_t i = m_size; i > 0; --i)
    {
        this->m_data[i] = this->m_data[i-1];
    }
    this->m_data[0] = element;
    this->m_size++;
}

template <typename T>
void Vector<T>::pushBack(T element)
{
    if(this->m_capacity <= this->m_size)
    {
        reserve((1+m_capacity) * 2);
    }
      this->m_data[m_size++] = element;
}

template <typename T>
void Vector<T>::erase(size_t idx)
{
    if (idx >= 0 && idx <= m_size)
    {
        for (size_t i = idx; i < m_size - 1; ++i)
        {
            m_data[i] = m_data[i + 1];
        }
    }
    m_size--;
}

template <typename T>
void Vector<T>::popFront()
//T front = m_data[0];
{
    for (size_t i = 0; i < m_size - 1; ++i)
    {
          m_data[i] = m_data[i+1];
    }
    m_size--;
    return front;

}

template <typename T>
T vector<T>::getElement(size_t idx)
{
    return this->m_data[idx];
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
void Vector<T>::setElement(size_t idx, T element)
{
    if (idx < this->m_size)
    this->m_data[idx] = element;
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
    for (size_t i = 0; i < this->m_size; ++i )
    {
        this->m_data[i] = 0;
    }
}

template <typename T>
bool Vector<T>::empty()
{
    if (m_size == 0) return true;
    return false;
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
void Vector<T>::print()
{
    for (size_t i = 0; i < this->m_size; ++i)
    std::cout << m_data[i] << " ";
}


 






































