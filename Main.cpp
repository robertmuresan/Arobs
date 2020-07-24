#include "Algorithms.hpp"
#include "List.hpp"
#include "ListNode.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "SynchronizedPriorityQueue.hpp"
#include "Task.hpp"
#include "TaskScheduler.hpp"
#include "Vector.hpp"
#include <iostream>

int main() 
{ 
    int array[10] = { 0, 3, 9, 2, 5, 6, 9, 31, 4, 0 };
    Vector<int> vec;
    vec.resize(10);
    std::cout << vec << std::endl;

    pdv::copy(array, array + 10, vec.begin());
    std::cout << vec << std::endl;

    pdv::sort(vec.begin(),vec.end(), [](int a, int b){return a < b;});
    std::cout << vec << std::endl;

    int sum = pdv::reduce(vec.begin(), vec.end(), 0, [](int a, int b) {return a + b;});
    std::cout << sum << "\n";

    Vector<int> vec1;
    vec1.resize(10);

    pdv::transform(vec.begin(),vec.end(), vec1.begin(), [](int a){ return ++a;});
    std::cout << vec1 << "\n";
  

  // Vector<int> vec;
  // vec.pushBack(1);
  // vec.pushBack(2);
  // vec.pushBack(3);
  // std::cout << vec[0] << std::endl; 
  // std::cout << vec[1] << std::endl; 
  // vec[0] = 10;
  // std::cout << vec[0] << std::endl; 
  // std::cout << vec[1] << std::endl; 

  // Vector<int> vec1;
  //vec1=vec;
   
  // std::cout << vec1;
  // vec.pushBack(0);
  // vec.pushBack(1);
  // vec.pushBack(2);
  // vec.pushBack(3);
  // vec.pushBack(4);
  // vec.pushFront(5);

  // Vector<int> vec2 = vec; 

  // vec.print();
  // std::cout<< vec.getFront() << " " << vec.getBack() << " " << vec.getElement(1) <<" " << std::endl;

  // std::cout << vec.getCapacity() << std::endl;
  // vec.reserve(15);
  // std::cout << vec.getCapacity() << std::endl;
  //vec.erase(2);
  //vec.print();


  // vec.popBack(); 
  // vec.popBack(); 
  // vec.popFront();
  // std::cout << "\n";
  // vec.print();


  // List<int> list;
  // list.pushBack(18);
  // list.pushBack(19);
  // list.pushFront(17);
  // std::cout <<list;

