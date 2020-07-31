#include "ListIterator.hpp"
#include "ListNode.hpp"
#include <iostream>


template <typename T>
ListIterator<T>::ListIterator(ListNode<T>* value):m_value(value){}

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
    if(m_value)
    {
        m_value = m_value->getNext();
    }
    return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator--()
{
    if(m_value)
    {
        m_value = m_value->getPrev();
    }
    return *this;
}

template <typename T>
 ListIterator<T>& ListIterator<T>::operator+=(std::size_t difference)
 {
     while(difference)
     {
         m_value = m_value->getNext();
         --difference;
     }
     return *this;
 }

 template <typename T>
 ListIterator<T>& ListIterator<T>::operator-=(std::size_t difference)
 {
    while(difference)
     {
         m_value = m_value->getPrev();
         --difference;
     }
     return *this;
 }

 template <typename T>
 ListIterator<T> ListIterator<T>::operator+(std::size_t difference)
 {
    while(difference)
     {
         m_value = m_value->getNext();
         --difference;
     }
     return *this;
 }

 template <typename T>
 ListIterator<T> ListIterator<T>::operator-(std::size_t difference)
 {
     while(difference)
     {
         m_value = m_value->getPrev();
         --difference;
     }
     return *this;
 }
 
 template <typename T>
 T& ListIterator<T>::operator*()
 {
     return m_value->getData(); 
 }

 template <typename T>
 ListNode<T>* ListIterator<T>::get_m_value()
 {
     return m_value;
 }
 