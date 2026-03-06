

# include "./includes/Base.hpp"
# include "./includes/A.hpp"
# include "./includes/B.hpp"
# include "./includes/C.hpp"

Base    *generate()
{
    int     x = rand() % 3;

    switch (x)
    {
        case 0 :
        {
            std::cout << "Generating A object" << std::endl;
            return (new A);
        }
        case 1 :
        {
            std::cout << "Generating B object" << std::endl;
            return (new B);
        }
        case 2 :
        {
            std::cout << "Generating C object" << std::endl;
            return (new C);
        }
    }
    return (NULL);
}

void    identify(Base *p)
{
    std::cout << "Pointer" << std::endl;
    if (dynamic_cast<A*>(p) != 0)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != 0)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != 0)
        std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    std::cout << "Reference" << std::endl;
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void) a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e){}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void) b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e){}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void) c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e){}
}

int main()
{
    srand(time(0));
    Base    *ptr = generate();
    Base    &ref = *ptr;

    identify(ptr);
    identify(ref);
    delete (ptr);
    return (0);
}