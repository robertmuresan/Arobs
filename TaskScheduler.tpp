#include "Task.hpp"
#include "SynchronizedPriorityQueue.hpp"
#include <future>
#include <thread>
#include <iostream>
#include <functional>

 TaskScheduler::TaskScheduler(std::size_t count)
 {
     for(std::size_t idx = 0; idx < count; ++idx)
     {
         m_threads.pushBack(std::thread(&TaskScheduler::processTasks, this));
     }
     m_stop = false;
 }

 TaskScheduler::~TaskScheduler()
 {
     m_stop = true;
     for(std::size_t idx = 0; idx < m_threads.getSize(); ++idx)
     {
         m_threads[idx].join();
     }
 }


 std::future<TaskResult> TaskScheduler::schedule(TaskArgument arg, std::int64_t prio)
 {
    auto lambda = [arg](){TaskResult a; a.sum = arg.a + arg.b; return a;};
    Task task(prio, lambda);

    std::packaged_task<TaskResult()> packedTask(task);
    
    std::future<TaskResult> futureTask = packedTask.get_future();
    
    m_tasks.push(std::move(packedTask));

    return futureTask;
 }

 void TaskScheduler::stop()
 {
     m_stop = true;
 }

#include "TaskScheduler.hpp"
#endif
