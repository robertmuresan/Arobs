#ifndef SPRIORITYQUEUE_HPP
#define SPRIORITYQUEUE_HPP
#include <cstddef>
#include <iostream>
#include <ostream>
#include <mutex>
#include "Vector.hpp"

template <typename T, template <typename> typename TContainer = Vector, typename TLock = std::mutex>
class SPRIORITYQUEUE_HPP{
    public:
        SPriorityQueue();
        SPriorityQueue(const SPriorityQueue& rhs);
        ~SPriorityQueue();

        SPriorityQueue<T, TContainer, TLock>& operator=(const SPriorityQueue& rhs);
        size_t getSize();

        void push(T element);
        T pop();
        bool tryPop(T& value);

        void clear();
        void empty();

    template <typename U, template <typename> typename UTContainer, typename UTLock>
    friend std::ostream& operator<<(std::ostream& os, const SPriorityQueue<U, UTContainer, UTLock>& pq);

    typename TContainer<T>::TIterator begin();
    typename TContainer<T>::TIterator end();

private:

     TContainer<T> m_container;
     TLock m_lock;

};     

#endif //SPRIORITYQUEUE_HPP



