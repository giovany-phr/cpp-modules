
#pragma once

# include <iostream>
# include <stdint.h>
# include <string>


struct Data{
    int         age;
    std::string name;
    std::string country;
};

class Serializer
{
    private : 
        Serializer();
        Serializer(const Serializer &other);

    public :
        ~Serializer();

        Serializer &operator = (const Serializer &other);

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};