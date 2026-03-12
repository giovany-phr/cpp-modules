
# include "./includes/Span.hpp"

int main()
{
    srand(time(NULL));
    std::cout << "==========CONSTRUCTORS==========" << std::endl;
    Span s(5);
    Span sp(5);
    Span spa(6);
    std::cout << "\n==========err FULL==========" << std::endl;
    try{
        s.addNumber(12);
        s.addNumber(112);
        s.addNumber(-122);
        s.addNumber(1);
        s.addNumber(112);
        s.addNumber(1);
        s.addNumber(1);
    }catch (std::exception &e){
        std::cerr << e.what();
    }
    
    try{
        sp.nbGenerator(15, 50);
    }catch (std::exception &e){
        std::cerr << e.what();
    }

    try{
        int i[7] = {1, 2, 10, 20, 42, 100, 200};
        std::list<int> l(i, i + 7);
        spa.addNumbers(l);
    }catch (std::exception &e){
        std::cerr << e.what();
    }
    // addNumbers function without multiple adNumber calls
    try{
        int i[6] = {1, 2, 10, 20, 100, 200};
        // std::list<int> c(i, i + 6);
        std::deque<int> c(i, i + 6);
        spa.addNumbers(c);
    }catch (std::exception &e){
        std::cerr << e.what();
    }
    std::cout << "\n==========ARRAYS==========" << std::endl;
    try{
        s.printNumbers();
        std::cout << "ShortestSpan = " << s.shortestSpan() << std::endl;
        std::cout << "LongestSpan = " << s.longestSpan() << "\n\n";
        sp.printNumbers();
        std::cout << "ShortestSpan = " << sp.shortestSpan() << std::endl;
        std::cout << "LongestSpan = " << sp.longestSpan() << "\n\n";
        spa.printNumbers();
        std::cout << "ShortestSpan = " << spa.shortestSpan() << std::endl;
        std::cout << "LongestSpan = " << spa.longestSpan() << std::endl;
    }catch (std::exception &e){
        std::cerr << "\n" << e.what();
    }
    std::cout << "\n==========DESTRUCTORS==========" << std::endl;
    return (0);
}

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }
