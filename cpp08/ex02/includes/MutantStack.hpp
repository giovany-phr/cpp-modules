
#pragma once
# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>

# include <list>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public :
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator = (const MutantStack &other);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator                iterator;
        typedef typename std::stack<T>::container_type::const_iterator          const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

        iterator begin();
        iterator end();
        const_iterator const_begin() const;
        const_iterator const_end() const;

        reverse_iterator rBegin();
        reverse_iterator rEnd();
        const_reverse_iterator const_rBegin() const;
        const_reverse_iterator const_rEnd() const;

        void addNumbers(unsigned int, int range);
        void printNumbers();
};

# include "MutantStack.tpp"