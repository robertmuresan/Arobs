#include "Queue.hpp" 
#include <iostream>

template <typename T, template <typename> typename TContainer>
Queue<T,TContainer>::Queue()
{
    new TContainer<T>();
}

template <typename T, template <typename> typename TContainer>
Queue<T,TContainer>::Queue(const Queue& rhs)
{
    m_container = rhs.m_container;
}

template <typename T, template <typename> typename TContainer>
Queue<T,TContainer>::~Queue()
{
    delete m_container;
}

template <typename T, template <typename> typename TContainer>
Queue<T,TContainer>& Queue<T,TContainer>::operator=(const Queue& rhs)
{
    m_container = rhs.m_container;
}

template <typename U, template <typename> typename UTContainer>
std::ostream& operator<<(std::ostream& os, const Queue<U,UTContainer>& q)
{
    os << q.m_container;
    return os;
}

template <typename T, template <typename> typename TContainer>
size_t Queue<T,TContainer>::getSize()
{
    return m_container.getSize();
}

template <typename T, template <typename> typename TContainer>
void Queue<T,TContainer>::push(T element)
{
    m_container.pushFront(element);
}

template <typename T, template <typename> typename TContainer>
T Queue<T,TContainer>::pop()
{
    T val = m_container.getBack();
    m_container.popBack();
    return val;
}

template <typename T, template <typename> typename TContainer>
void Queue<T,TContainer>::clear()
{
    m_container.clear();
}

template <typename T, template <typename> typename TContainer>
bool Queue<T,TContainer>::empty()
{
    return m_container.empty();
}

template <typename T, template <typename> typename TContainer>
void Queue<T,TContainer>::print()
{
    m_container.print();
}
