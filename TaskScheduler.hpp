#ifndef TASKSCHEDULER_HPP
#define TASKSCHEDULER_HPP
#include "SynchronizedPriorityQueue.hpp"
#include "Task.hpp"
#include <iostream>
#include <future>
#include <thread>
#include <atomic>

class TaskScheduler
{
   public:
       TaskScheduler(std::size_t count);
       ~TaskScheduler();

       std::future<TaskResult> schedule(TaskArgument arg, std::int64_t prio);
       void stop();

    private:
       SPriorityQueue<std::packaged_task<Task>> m_tasks;
       Vector<std::thread> m_thread;
       std::atomic<bool> m_stop;

       void processTasks();
};

#endif //TASKSCHEDULER_HPP