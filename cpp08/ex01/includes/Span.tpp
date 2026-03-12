
# include "Span.hpp"


template <typename T>
void Span::addNumbers(T &c)
{
    if (this->_N - this->_mSet.size() < c.size())
        throw rangeTooBig();
    this->_mSet.insert(this->_mSet.begin(), c.begin(), c.end());
    return ;
}