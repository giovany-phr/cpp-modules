
#pragma once
# include <iostream>
# include <string>
# include <exception>
# include <ctime>
# include <cstdlib>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

class Span
{
    private :
        std::vector<int> _mSet;
        unsigned int    _N;

    public :
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        ~Span();
        Span &operator = (const Span &other);

        int shortestSpan();
        int longestSpan();

        void    addNumber(int nb);
        void    nbGenerator(unsigned int nbElement, int range);
        void    printNumbers();

        template <typename T>
        void addNumbers(T &c);


        class arrayIsFull : public std::exception
        {
            virtual const char *what() const throw();
        };

        class arrayTooSmall : public std::exception
        {
            virtual const char *what() const throw();
        };

        class rangeTooBig : public std::exception
        {
            virtual const char *what() const throw();
        };
};

# include "Span.tpp"