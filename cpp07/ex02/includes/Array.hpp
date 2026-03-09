
#pragma once

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <exception>

template<typename T>
class Array
{
    private : 
        T               *_array;
        unsigned int    _size;

    public : 
        Array() : _size(0)
        {
            std::cout << "Array default constructor called" << std::endl;
            this->_array = new T[0];
        }

        Array(unsigned int n) : _size(n)
        {
            std::cout << "Array constructor called" << std::endl;
            if (this->_size < 0)
                throw errorIndex();
            this->_array = new T[this->_size];
        }

        Array(const Array &other)
        {
            std::cout << "Array copy constructor called" << std::endl;
            this->_array = NULL;
            *this = other;
        }

        Array &operator = (const Array &other)
        {
            std::cout << "Array assignement constructor called" << std::endl;
            if (this->_array)
                delete [] this->_array;
            if (other.size() != 0)
            {
                this->_size = other.size();
                this->_array = new T[this->_size];
                for (unsigned int i = 0; i < this->_size; i++)
                    this->_array[i] = other._array[i];
            }
            return (*this);
        }

        T &operator [] (unsigned int index)
        {
            if (this->_array == NULL || size() <= index)
                throw errorIndex();
            return (this->_array[index]);
        }

        ~Array()
        {
            std::cout << "Array destructor called" << std::endl;
            if (_array != NULL)
                delete [] this->_array;
        }

        unsigned int size() const
        {
            return (this->_size);
        }

        class errorIndex : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("Error: index given is out of bound\n");
            }
        };
};