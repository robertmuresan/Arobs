#include <iostream>
#include "LargeObject.hpp"
#include <cstdlib>

LargeObject::LargeObject()
{
    for(size_t i = 0; i < LARGE_OBJECT_SIZE; ++i)
    {
        m_data[i] = std::rand();
    }
}

LargeObject::~LargeObject()
{
    for(size_t i = 0; i < LARGE_OBJECT_SIZE; ++i)
    {
        m_data[i] = 0;
    }
}