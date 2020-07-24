#include <iostream>

namespace pdv
{
    template <typename TInputIt, typename TOutputIt>
    TOutputIt copy(TInputIt first, TInputIt last, TOutputIt output)
    {
        for(; first != last; ++first)
        {
            *output = *first;
            ++output;
        }
        return output;
    }

    template <typename TInputIt, typename TOutputIt, typename TPredicate>
    TOutputIt copyif(TInputIt first, TInputIt last, TOutputIt output, TPredicate pred)
    {
        for(; first != last; ++first)
        {
            if(pred(*first))
            {
                *output = *first;
                ++output;
            }
        }
        return output;
    }

    template <typename TInputIt, typename T>
    TInputIt find(TInputIt first, TInputIt last, T value)
    {
        for(; first != last; ++first)
        {
            if(*first == value)
            {
                return first;
            } 
        }
        return last;
    }

    template <typename TInputIt, typename TPredicate>
    TInputIt findif(TInputIt first, TInputIt last, TPredicate pred)
    {
        for(; first != last; ++first)
        {
            if(pred(*first))
            {
                return first;
            } 
        }
        return last;
    }

    template <typename TInputIt, typename T>
    std::size_t count(TInputIt first, TInputIt last, T value)
    {
        std::size_t val = 0;
        for(; first != last; ++first)
        {
            if(*first == value)
            {
                ++val;
            }
        }
        return val;
    }

    template <typename TInputIt, typename TPredicate>
    std::size_t countif(TInputIt first, TInputIt last, TPredicate pred)
    {
        std::size_t val = 0;
        for(; first != last; ++first)
        {
            if(pred(*first))
            {
                ++val;
            }
        }
        return val;
    }

    template <typename TInputIt, typename T>
    void fill(TInputIt first, TInputIt last, T value)
    {
        for(; first != last; ++first)
        {
            *first = value;
        }
    }

    template <typename TInputIt, typename TComparator>
    void sort(TInputIt first, TInputIt last, TComparator comp)
    {
    for (TInputIt i = first; first != last - 1; ++first)
    {
        for (TInputIt j = i + 1; j != last; ++j)
        {
            if (comp(*i, *j))
            {
                std::swap(i, j);
            }
        }
    }
    }

    template <typename TLhsInputIt, typename TRhsInputIt>
    bool equal(TLhsInputIt lhsFirst, TLhsInputIt lhsLast, TRhsInputIt rhsFirst)
    {
        for(; lhsFirst != lhsLast; ++lhsFirst)
        {
            if(!(*lhsFirst == *(++rhsFirst)))
            {
                return false;
            }
        }
        return true;
    }

    template <typename TInputIt, typename TPredicate>
    bool anyOf(TInputIt first, TInputIt last, TPredicate pred)
    {
        for(; first != last; ++first)
        {
            if(pred(*first))
            {
                return true;
            }
        }
        return false;
    }

    template <typename TInputIt, typename TPredicate>
    bool allOf(TInputIt first, TInputIt last, TPredicate pred)
    {
        for(; first != last; ++first)
        {
            if(!pred(*first))
            {
                return false;
            }
        }
        return true;
    }

    template <typename TInputIt, typename TPredicate> 
    bool noneOf(TInputIt first, TInputIt last, TPredicate pred)
    {
        for(; first != last; ++first)
        {
            if(pred(*first))
            {
                return false;
            }
        }
        return true;
    }

    template <typename TInputIt, typename TOutputIt, typename TUnaryFunc>
    TOutputIt transform(TInputIt first, TInputIt last, TOutputIt output, TUnaryFunc func)
    {
        for(; first != last; ++first)
        {
            *output = func(*first);
            ++output;
        }
        return output;
    }

    template <typename TInputIt, typename T, typename TBinaryFunc>
    T reduce(TInputIt first, TInputIt last, T initValue, TBinaryFunc func)
    {
        for(; first != last; ++first)
        {
           initValue = func(*first, initValue);
        }
        return initValue;
    }   
}