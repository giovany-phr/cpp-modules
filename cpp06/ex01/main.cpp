

#include "./includes/Serializer.hpp"

int main()
{
    uintptr_t   raw;
    Data        *doe = new Data;
    Data        *peter;

    doe->age = 42;
    doe->name = "Peter";
    doe->country = "England";

    std::cout << "=== Doe DATA ===" << std::endl
    << doe->age << std::endl
    << doe->name << std::endl
    << doe->country << std::endl;

    raw = Serializer::serialize(doe);
    peter = Serializer::deserialize(raw);

    std::cout << "\n=== Peter DATA ===" << std::endl
    << peter->age << std::endl
    << peter->name << std::endl
    << peter->country << std::endl;

    delete (doe);
    return (0);
}