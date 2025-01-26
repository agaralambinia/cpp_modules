#ifndef WHATEVER
# define WHATEVER

#include <iostream>

template <typename Whatever>
void swap(Whatever &a, Whatever &b)
{
    Whatever tmp = a;
    a = b;
    b = tmp;
}

template <typename Whatever>
void swap(const Whatever &a, const Whatever &b)
{
    Whatever tmp = a;
    a = b;
    b = tmp;
}

template <typename Whatever>
Whatever min(Whatever a, Whatever b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

template <typename Whatever>
Whatever max(Whatever a, Whatever b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

#endif
