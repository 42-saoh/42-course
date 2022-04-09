#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *array, int len, void(*func)(T const &t))
{
    if (!array || len <= 0)
        return ;
    for (int i = 0; i < len; i++)
        func(array[i]);
}

#endif