
# include "MutantStack.hpp"

/**************************************************************/
/***************** CONSTRUCTORS/DESTRUCTORS *******************/
/**************************************************************/

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    std::cout << "MutantStack default constructor called" <<std::endl;
} 

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{
    std::cout << "MutantStack copy constructor called" <<std::endl;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack &other)
{
    std::cout << "MutantStack assignement constructor called" <<std::endl;
    if (this != &other)
        this->c = other.c;
    return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack destructor called" <<std::endl;
}

/**************************************************************/
/********************* ITERATOR FUNCTIONS *********************/
/**************************************************************/

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return(std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return(std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::const_begin() const
{
    return(std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::const_end() const
{
    return(std::stack<T>::c.end());
}

/*****************************************************************/
/*****************************************************************/

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rBegin()
{
    return(std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rEnd()
{
    return(std::stack<T>::c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::const_rBegin() const
{
    return(std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::const_rEnd() const
{
    return(std::stack<T>::c.rend());
}

/**************************************************************/
/********************** EXTRA FUNCTIONS ***********************/
/**************************************************************/

template<typename T>
void MutantStack<T>::addNumbers(unsigned int nbElement, int range)
{
    if (range == 0)
        for (unsigned int i = 0; i < nbElement; i++)
            this->push(0);
    if (range > 0)
        for (unsigned int i = 0; i < nbElement; i++)
            this->push(rand() % range);
    else
    {
        range *= -1;
        for (unsigned int i = 0; i < nbElement; i++)
            this->push((rand() % range) * -1);
    }
}

template<typename T>
void MutantStack<T>::printNumbers()
{
    std::cout << "[";
    for (MutantStack<T>::iterator it = this->begin(); it != this->end(); it++)
    {
        if (it == this->begin())
            std::cout << *it;
        else
            std::cout << ", " << *it;
    }
    std::cout << "]" << std::endl;
}
