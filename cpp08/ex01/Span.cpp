
# include "./includes/Span.hpp"

/**************************************************************/
/***************** CONSTRUCTORS/DESTRUCTORS *******************/
/**************************************************************/

Span::Span() : _N(0)
{
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &other)
{
    std::cout << "Span copy constructor called" << std::endl;
    *this = other;
}

Span &Span::operator = (const Span &other)
{
    std::cout << "Span assignement constructor called" << std::endl;
    if (this != &other)
    {
        this->_N = other._N;
        this->_mSet = other._mSet;
    }
    return (*this);
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

/**************************************************************/
/********************** MEMBER FUNCTIONS **********************/
/**************************************************************/

int Span::shortestSpan()
{
    int span;
    int temp;

    if (this->_mSet.size() <= 1)
        throw arrayTooSmall();
    std::sort(this->_mSet.begin(), this->_mSet.end());
    for (std::vector<int>::iterator it = this->_mSet.begin(); it != this->_mSet.end(); it++)
    {
        if ((it) == this->_mSet.begin())
            span = (*it - *(it + 1)) * -1;
        else if ((it + 1) != this->_mSet.end())
        {
            temp = (*it - *(it + 1)) * -1;
            if (temp < span)
                span = temp;
        }
    }
    return (span);
}

int Span::longestSpan()
{
    int span;
    std::vector<int>::iterator first;
    std::vector<int>::iterator last;

    if (this->_mSet.size() <= 1)
        throw arrayTooSmall();
    std::sort(this->_mSet.begin(), this->_mSet.end());
    first = this->_mSet.begin();
    last = this->_mSet.end() - 1;
    span = (*first - *last) * -1;
    return (span);
}

void Span::addNumber(int nb)
{
    if (this->_mSet.size() == this->_N)
        throw arrayIsFull();
    this->_mSet.push_back(nb);    
}

void Span::nbGenerator(unsigned int nbElement, int range)
{
    if (range == 0)
        for (unsigned int i = 0; i < nbElement; i++)
            addNumber(0);
    if (range > 0)
        for (unsigned int i = 0; i < nbElement; i++)
            addNumber(rand() % range);
    else
    {
        range *= -1;
        for (unsigned int i = 0; i < nbElement; i++)
            addNumber((rand() % range) * -1);
    }
}

void Span::printNumbers()
{
    if (this->_mSet.size() <= 0)
        return ;
    std::cout << "[";
    for (std::vector<int>::iterator it = this->_mSet.begin(); it != this->_mSet.end(); it++)
    {
        if (it == _mSet.begin())
            std::cout << *it;
        else
            std::cout << ", " << *it;
    }
    std::cout << "]" << std::endl;
}

/**************************************************************/
/******************** EXCEPTION FUNCTIONS *********************/
/**************************************************************/

const char *Span::arrayIsFull::what() const throw()
{
    return ("Error: Impossible To Add More Number, The Array Is Full\n");
}

const char *Span::arrayTooSmall::what() const throw()
{
    return ("Error: Impossible To Find Span, Not Enough Elements\n");
}

const char *Span::rangeTooBig::what() const throw()
{
    return ("Error: Impossible To Add Numbers, Range Of Iterator Is Too Big\n");
}