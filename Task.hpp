#ifndef TASK_HPP
#define TASK_HPP
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "TaskArgument.hpp"
#include "TaskResult.hpp"

class Task{
    public:
    Task(std::int64_t prio, std::function<TaskResult()> func);

    TaskResult operator()();
    bool operator<(const Task& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Task& t);
    std::function<TaskResult()> get_m_function();
    
private:
    std::int64_t m_priority;
    std::function<TaskResult()> m_function;
    std::int64_t getPriority();
};

#include "Task.tpp"
#endif 