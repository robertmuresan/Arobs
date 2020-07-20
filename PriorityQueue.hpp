#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <cstddef>

template <typename T, template <typename> typename TContainer>
class PriorityQueue
{
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& rhs);
    ~PriorityQueue();

    PriorityQueue<T,TContainer>& operator=(const PriorityQueue& rhs);

    size_t getSize();

    void push(T element);
    T pop();

    void clear();
    bool empty();

    template <typename U, template <typename> typename UTContainer>
    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue<U,UTContainer>& pq);

private:

    TContainer<T> m_container;
    void print();
};

#include "PriorityQueue.tpp"
#endif  //PRIORITYQUEUE_HPP