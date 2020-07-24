#include "SynchronizedPriorityQueue.hpp"

template <typename T, template <typename> typename TContainer, typename TLock>
SPriorityQueue<T,TContainer,TLock>::SPriorityQueue()
{
    //new TContainer<T>();
}

template <typename T, template <typename> typename TContainer, typename TLock>
SPriorityQueue<T,TContainer,TLock>::SPriorityQueue(const SPriorityQueue& rhs)
{
    m_container = rhs.m_container;
}

template <typename T, template <typename> typename TContainer, typename TLock>
SPriorityQueue<T,TContainer,TLock>::~SPriorityQueue()
{

}

template <typename T, template <typename> typename TContainer, typename TLock>
SPriorityQueue<T,TContainer,TLock>& SPriorityQueue<T,TContainer,TLock>::operator=(const SPriorityQueue& rhs)
{
    m_lock.lock();
    m_container = rhs.m_container;
    m_lock.unlock();
}

template <typename U, template <typename> typename UTContainer, typename UTLock>
std::ostream& operator<<(std::ostream& os, const SPriorityQueue<U,UTContainer,UTLock>& q)
{
    os << q.m_container;
    return os;
}

template <typename T, template <typename> typename TContainer, typename TLock>
size_t SPriorityQueue<T,TContainer, TLock>::getSize()
{
    m_lock.lock();
    size_t size = m_container.getSize();
    m_lock.unlock();
    return size;
}

template <typename T, template <typename> typename TContainer, typename TLock>
void SPriorityQueue<T,TContainer, TLock>::push(T task)
{
    std::size_t pos = 0;
    m_lock.lock();
    for (std::size_t idx = 0; idx < m_container.getSize(); ++idx)
    {
        if (m_container.getElement() < task)
        {
            pos++;
        }
    }
    m_container.insert(pos, task);
    m_lock.unlock();
}

template <typename T, template <typename> typename TContainer, typename TLock>
T SPriorityQueue<T,TContainer,TLock>::pop()
{
    m_lock.lock();
    T task = m_container.getBack();
    m_container.popBack();
    m_lock.unlock();
    return task;
}

template <typename T, template <typename> typename TContainer, typename TLock>
bool SPriorityQueue<T,TContainer,TLock>::tryPop(T& value)
{
    m_lock.lock();
    if(!m_container.isEmpty())
    {
        value = m_container.pop();
        return true;
    }
    return false;
}

template <typename T, template <typename> typename TContainer, typename TLock>
void SPriorityQueue<T,TContainer,TLock>::clear()
{
    m_lock.lock();
    m_container.clear();
    m_lock.unlock();
}

template <typename T, template <typename> typename TContainer, typename TLock>
bool SPriorityQueue<T,TContainer,TLock>::empty()
{   
    m_lock.lock();
    bool emp = m_container.empty();
    m_lock.unlock();
    return emp;
}

template <typename T, template <typename> typename TContainer, typename TLock>
typename TContainer<T>::TIterator SPriorityQueue<T,TContainer,TLock>::begin()
{
    m_lock.lock();
    typename TContainer<T>::TIterator it = m_container.begin();
    m_lock.unlock();
    return it;
}

template <typename T, template <typename> typename TContainer, typename TLock>
typename TContainer<T>::TIterator SPriorityQueue<T,TContainer,TLock>::end()
{
    m_lock.lock();
    typename TContainer<T>::TIterator it = m_container.end();
    m_lock.unlock();
    return it;
}