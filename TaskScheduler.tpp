#include "TaskScheduler.hpp"
#include <future>
#include <iostream>

 TaskScheduler::TaskScheduler(std::size_t count)
 {
 }

 TaskScheduler::~TaskScheduler()
 {
 }

 std::future<TaskResult> TaskScheduler::schedule(TaskArgument arg, std::int64_t prio)
 {
 }

 void TaskScheduler::stop()
 {
 }