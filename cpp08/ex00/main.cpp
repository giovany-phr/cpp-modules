
# include "./includes/easyfind.hpp"

int main()
{
    std::cout << "======= VECTOR CONTAINER ======" << std::endl;
    srand(time(NULL));
    int nbr[6] = {1, 2, 3, 4, 42, 5};
    std::vector<int> v(nbr, nbr + 6);
    std::vector<int> ve(5, (rand()));
    std::vector<int> vec;
    std::vector<int> vect;
    vect.push_back(10);
    vect.push_back(0);
    vect.push_back(154);
    vect.push_back(42);

    try{
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::vector<int>::iterator it = easyfind(ve, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::vector<int>::iterator it = easyfind(vect, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }

    std::cout << "\n======= LIST CONTAINER ======" << std::endl;

    const int nb[6] = {42, 5452, 789, 2, 0, 7};
    std::list<int> l(nb, nb + 6);
    std::list<int> li(vec.begin(), vec.end());
    std::list<int> lis(l);

    try{
        std::list<int>::iterator it = easyfind(l, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::list<int>::iterator it = easyfind(li, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::list<int>::iterator it = easyfind(lis, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }

    std::cout << "\n======= DEQUE CONTAINER ======" << std::endl;

    const int n[6] = {4242, 5452, 789, 2, 0, 7};
    std::deque<int> d(n, n + 6);
    std::deque<int> de(l.begin(), l.end());
    std::deque<int> deq(de);
    std::deque<int> dequ;
    dequ.push_back(8);
    dequ.push_back(7);
    dequ.push_back(8);
    dequ.push_back(4);
    dequ.push_front(42);

    try{
        std::deque<int>::iterator it = easyfind(d, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::deque<int>::iterator it = easyfind(de, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::deque<int>::iterator it = easyfind(deq, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::deque<int>::iterator it = easyfind(dequ, 42);
        std::cout << "occurence found here : " << *it << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }

    // std::cout << "\n======= TEST CONTAINER ======" << std::endl;

    // std::list<int> arr;

    // addNumber(arr, 100, 50);
    // printNumbers(arr);

    // try{
    //     std::list<int>::iterator it = easyfind(arr, 42);
    //     std::cout << "occurence found here : " << *it << std::endl;
    // }
    // catch (std::exception &e){
    //     std::cerr << e.what();
    // }
}