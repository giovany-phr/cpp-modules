
#include "./includes/iter.hpp"

int main()
{
    int         intArray[7] = {-2,0,1,2,3,4,5};
    double      dblArray[7] = {-2.5,0,0.1, 1.0, 2.9, 10};
    char        str[] = "GdkknVnqkc";
    const char  *constStr = "GdkknVnqkc";
    std::string src[2] = {"hello", " world"};

    std::cout << "======INT======" << std::endl;
    iter(intArray, 7, iterUp<int>);
    for (int i = 0; i < 7; i++)
        std::cout << intArray[i] << "| ";
    std::cout << std::endl;
    iter(intArray, 7, iterDown<int>);
    for (int i = 0; i < 7; i++)
        std::cout << intArray[i] << "| ";
    std::cout << std::endl;

    std::cout << "\n======DOUBLE======" << std::endl;
    iter(dblArray, 7, iterUp<double>);
    for (int i = 0; i < 7; i++)
        std::cout << dblArray[i] << "| ";
    std::cout << std::endl;
    iter(dblArray, 7, iterDown<double>);
    for (int i = 0; i < 7; i++)
        std::cout << dblArray[i] << "| ";
    std::cout << std::endl;

    std::cout << "\n======CHAR======" << std::endl;
    iter(str, 10, iterUp<char>);
    std::cout << str << std::endl;
    iter(str, 10, ft_toUpper<char>);
    std::cout << std::endl;
    iter(str, 10, iterDown<char>);
    std::cout << str << std::endl;
    
    std::cout << "\n======const CHAR======" << std::endl;
    std::cout << constStr << std::endl;
    iter<const char>(constStr, 10, ft_toUpper<const char>);
    std::cout << std::endl;
    return (0);
}