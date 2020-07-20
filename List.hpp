#ifndef LIST_HPP
#define LIST_HPP
#include <cstddef>
#include "ListNode.hpp"

template <typename T>
class List
{
    public:
    List();
    List(const List& rhs);
    ~List();

    const T& operator[](std::size_t idx) const;
    T& operator[](std::size_t idx);
    List<T>& operator=(const List<T>& rhs);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& vec);

    void insert(size_t idx, T element);
    void pushFront(T element);
    void pushBack(T element);

    T getElement(size_t idx);
    T getFront();
    T getBack();
    size_t getSize();

    void erase(size_t idx);
    void popFront();
    void popBack();

    T setElement(size_t idx, T element);
    T setFront(T element);
    T setBack(T element);

    void clear();
    bool empty();
    void print();

    private:
        size_t m_size;
        ListNode<T>* m_head;
        ListNode<T>* m_tail;
};

#include "List.tpp"
#endif //LIST_HPP
