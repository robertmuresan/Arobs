#include "ListIterator.hpp"
#include <iostream>


template <typename T>
ListIterator<T>::ListIterator(T* value):m_value(value){}

template <typename T>
ListIterator<T>::ListIterator(const ListIterator& rhs):m_value(rhs.m_value){}

template <typename T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator& rhs)
{
    m_value = rhs.m_value;
    return *this;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator& rhs)
{
    return m_value != rhs.m_value;
}

template <typename T>
bool ListIterator<T>::operator<(const ListIterator& rhs)
{
    return m_value < rhs.m_value;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++()
{
    ++m_value;
    return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator--()
{
    --m_value;
    return *this;
}

template <typename T>
 ListIterator<T>& ListIterator<T>::operator+=(std::size_t difference)
 {
     m_value += difference;
     return *this;
 }

 template <typename T>
 ListIterator<T>& ListIterator<T>::operator-=(std::size_t difference)
 {
     m_value -= difference;
     return *this;
 }

 template <typename T>
 ListIterator<T> ListIterator<T>::operator+(std::size_t difference)
 {
     ListIterator<T> el;
     el = m_value + difference;
     return el;
 }

 template <typename T>
 ListIterator<T> ListIterator<T>::operator-(std::size_t difference)
 {
     ListIterator<T> it;
     it = m_value - difference;
     return it;
 }
 
 template <typename T>
 T& ListIterator<T>::operator*()
 {
     return *m_value;
 }