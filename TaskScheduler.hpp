#ifndef TASKSCHEDULER_HPP
#define TASKSCHEDULER_HPP
#include "SynchronizedPriorityQueue.hpp"
#include "Task.hpp"
#include <iostream>
#include <future>
#include <thread>
#include <atomic>
#include "Vector.hpp"

class TaskScheduler
{
   public:
       TaskScheduler(std::size_t count);
       ~TaskScheduler();

       std::future<TaskResult> schedule(TaskArgument arg, std::int64_t prio);
       void stop();

    private:
       SPriorityQueue<std::packaged_task<TaskResult()>> m_tasks;
       Vector<std::thread> m_threads;
       std::atomic<bool> m_stop;

       void processTasks();
       {
           while(!m_stop)
         {
            std::packaged_task<TaskResult()> popRez;
            if(m_tasks.tryPop(popRez))
            {
                popRez();
            }
         }
       }
};

#include "TaskScheduler.tpp"
#endif 