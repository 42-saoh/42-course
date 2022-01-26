#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename Func>
void iter(T *array, int len, Func &func)
{
    if (!array || len <= 0)
        return ;
    for (int i = 0; i < len; i++)
        func(array[i]);
}

#endif