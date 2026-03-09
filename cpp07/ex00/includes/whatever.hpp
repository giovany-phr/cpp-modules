
#pragma once
# include <string>
# include <iostream>
# include <cctype>


/////////////////////////////////////
////////////--SWAP--////////////////

template<typename T>
void swap (T *x, T *y)
{
    T temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

template<typename T>
void swap (T &x, T &y)
{
    T temp;

    temp = x;
    x = y;
    y = temp;
}

/////////////////////////////////////
/////////////--MAX--/////////////////

template<typename T>
T max (T *x, T *y)
{return ((*x > *y) ? *x : *y);}

template<typename T>
T max (T &x, T &y)
{return ((x > y) ? x : y);}

/////////////////////////////////////
/////////////--MIN--/////////////////

template<typename T>
T min (T *x, T *y)
{return ((*x < *y) ? *x : *y);}

template<typename T>
T min (T &x, T &y)
{return ((x < y) ? x : y);}
