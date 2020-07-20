#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string.h>

template <typename T>
class Vector{
    public:

      Vector();
      Vector(const Vector& rhs);
      ~Vector();

      size_t getSize();
      size_t getCapacity();

      const T& operator[](std::size_t idx) const;
      T& operator[](std::size_t idx);
      Vector <T>& operator=(const Vector& rhs);

      template<typename U>
      friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);

      void insert(size_t idx, T element);

      void pushFront(T element);
      void pushBack(T element);

      void erase(size_t idx);

      void popFront();
      void popBack()

      T getElement(size_t idx);
      T getFront();
      T getBack();

      void setElement(size_t idx, T element);
      void setFront(T element);
      void setBack(T element);

      void clear();
      void empty();
      void print();
      void reserve(size_t newCapacity);
       


    private:
        size_t m_capacity;
        size_t m_size;
        T* m_data;

};


#include "Vector.tpp"
#endif //VECTOR_HPP