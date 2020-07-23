#include "Task.hpp"
#include <iostream> 
#include <ostream>
#include <string.h>

Task::Task() 
{
    m_description = NULL;
    m_priority = -1;
}

std::string Task::getDescription()
{
    return m_description;
}

int8_t Task::getPriority()
{
    return m_priority;
}

bool Task::operator<(const Task& rhs)
{
    if(m_priority < rhs.m_priority)
    {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Task& t)
{
    os << "description: " 
       << t.m_description << "\n";
    os << "priority: "
       << t.m_priority << "\n";

    return os;
}