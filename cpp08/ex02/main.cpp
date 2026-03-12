
# include "./includes/MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n========= LIST CONTAINER =========" << std::endl;
    srand(time(NULL));
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    std::list<int>::iterator itLst = lst.begin();
    std::list<int>::iterator iteLst = lst.end();
    ++itLst;
    --itLst;
    while (itLst != iteLst)
    {
    std::cout << *itLst << std::endl;
    ++itLst;
    }
    std::stack<int, std::list<int> > sLst(lst);
    return (0);
}

// int main()
// {
//     srand(time(NULL));
//     MutantStack<int> mutant;

//     mutant.addNumbers(10, 10);
//     mutant.printNumbers();
//     MutantStack<int>::iterator it = mutant.begin();
//     MutantStack<int>::const_iterator ite = mutant.const_begin();
//     MutantStack<int>::reverse_iterator r_it = mutant.rBegin();
//     MutantStack<int>::const_reverse_iterator r_ite = mutant.const_rBegin();

//     std::cout << "\n=========ITERATOR=========" << std::endl;
//     while(it != mutant.end())
//     {
//         std::cout << *it << " ";
//         it++;
//     }
//     std::cout << "\n======CONST ITERATOR======" << std::endl;
//     while(ite != mutant.end())
//     {
//         std::cout << *ite << " ";
//         ite++;
//     }
//     std::cout << "\n========R_ITERATOR========" << std::endl;
//     while(r_it != mutant.rEnd())
//     {
//         std::cout << *r_it << " ";
//         r_it++;
//     }
//     std::cout << "\n=====CONST R_ITERATOR=====" << std::endl;
//     while(r_ite != mutant.rEnd())
//     {
//         std::cout << *r_ite << " ";
//         r_ite++;
//     }
//     std::cout << "\n" << std::endl;
//     return 0;
// }