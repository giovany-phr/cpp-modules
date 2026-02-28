#pragma once

# include <string>
# include <iostream>

class Brain
{
    private : 
        std::string _ideas[100];

    public :
        Brain();
        Brain(std::string *ideas);
        Brain(const Brain &other);
        virtual ~Brain();

        Brain &operator = (const Brain &other);

        void        setIdea(size_t index, std::string idea);
        std::string getIdea(size_t index);
        std::string *getIdAdress(size_t i);
};