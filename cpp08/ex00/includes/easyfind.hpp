
#pragma once
# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include <ctime>

# include <algorithm>
# include <vector>
# include <list>
# include <deque>

template <typename T>
typename T::iterator easyfind(T &occur, int src);

// template<typename T>
// void addNumbers(T &container, int size, int range);

// template<typename T>
// void printNumbers(T &container);

class occurNotFound : public std::exception
{
    virtual const char *what() const throw(){
        return ("Occurence Not Found\n");
    }
};

#include "easyfind.tpp"