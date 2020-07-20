#ifndef LISTNODE_HPP
#define LISTNODE_HPP
#include <cstddef>

template <typename T>
class ListNode{
public:

   ListNode(ListNode* prev, ListNode * next, T data);
   ListNode(const ListNode& rhs);
   ~ListNode();

   ListNode<T>& operator=(const ListNode& rhs);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const ListNode<U>& vec);

   ListNode* getPrev();
   ListNode* getNext();

   void setPrev(ListNode* prev);
   void setNext(ListNode* next);

   T& getData();
   void setData(ListNode* data);
   void setDataT(T data);

   void print();

    
private:

    ListNode* m_prev;
    ListNode* m_next;
    T m_data;
};

#include "ListNode.cpp"
#endif  //LISTNODE_HPP