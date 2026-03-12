
#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &occur, int toFind)
{
    typename T::iterator   it;

    it = std::find(occur.begin(), occur.end(), toFind);
    if (it == occur.end())
        throw occurNotFound();
    return (it);
}

// template<typename T>
// void printNumbers(T &container)
// {
//     typename T::iterator it;
//     std::cout << "[";
//     for (it = container.begin(); it != container.end(); it++)
//     {
//         if (it == container.begin())
//             std::cout << *it;
//         else
//             std::cout << ", " << *it;
//     }
//     std::cout << "]" << std::endl;
// }

// template<typename T>
// void addNumber(T &container, int size, int range)
// {
//     typename T::iterator it;

//     for (int i = 0; i < size; i++)
//         container.push_back(rand() % range);
// }
