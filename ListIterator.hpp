#ifndef LISTERATOR_HPP
#define LISTERATOR_HPP
#include <iostream>
#include "ListNode.hpp"

template <typename T>
class ListIterator{

   public:
        ListIterator(ListNode<T>* value);
        ListIterator(const ListIterator& rhs);
        ListIterator& operator=(const ListIterator& rhs);

        bool operator!=(const ListIterator& rhs);
        bool operator<(const ListIterator& rhs);

        ListIterator& operator++();
        ListIterator& operator--();

        ListIterator& operator+=(std::size_t difference);
        ListIterator& operator-=(std::size_t difference);
        ListIterator operator+(std::size_t difference);
        ListIterator operator-(std::size_t difference);

        T& operator*();

        ListNode<T>* get_m_value();

    private:

    ListNode<T>* m_value;
};

#include "ListIterator.tpp"
#endif //LISTERATOR_HPP