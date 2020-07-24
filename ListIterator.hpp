#ifndef LISTERATOR_HPP
#define LISTERATOR_HPP
#include <iostream>

template <typename T>
class ListIterator{

   public:
        ListIterator(T* value);
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

    private:

    T* m_value;
};

#include "ListIterator.tpp"
#endif //LISTERATOR_HPP