
#pragma once
# include <string>
# include <iostream>

template<typename T>
void iter(T *array, size_t len, void(*f)(T &))
{
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}

template<typename T>
void iter(T const *array, size_t len, void(*f)(T const &))
{
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}

template<typename T1, typename T2>
void iter(T1 *array, size_t len, T2 funct)
{
    for (size_t i = 0; i < len; i++)
        funct(array[i]);
}

template<typename T>
void iterUp (T &x)
{x++;}

template<typename T>
void iterDown (T &x)
{x--;}

template<typename T>
void ft_toUpper (T &x)
{
    if (97 <= x && x <= 122)
        std::cout << static_cast<char>(x - 32);
    else 
        std::cout << static_cast<char>(x);
    return ;
}
