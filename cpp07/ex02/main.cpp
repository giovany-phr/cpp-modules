
# include "./includes/Array.hpp"
# include <iostream>

#define MAX_VAL 750
#define NBR_VAL 10

int main()
{
    srand(time(NULL));
    std::cout << "======Constructors======" << std::endl;
    Array<int> intNULL;
    Array<int> intArray(NBR_VAL);
    Array<char> charArray(NBR_VAL);
    Array<double> dblArray(NBR_VAL);            
    Array<std::string> strArray(NBR_VAL);

    int *intMirror = new int[NBR_VAL];                  // value to compare with real Array
    std::string *strMirror = new std::string[NBR_VAL];  // value to compare with real Array
    char *charMirror = new char[NBR_VAL];               // value to compare with real Array

    std::cout << "\n======Array Test======" << std::endl;
    /****************************************************/
    /*****************Inialising Arrays******************/
    /****************************************************/
    for (int i = 0; i < NBR_VAL; i++)
    {
        std::string value;
        if (i % 2 == 0)
            value = "Hello";
        else
            value = "World";
        strArray[i] = value;
        strMirror[i] = value; // value to compare with real Array
    }
    for (int i = 0; i < NBR_VAL; i++)
    {
        const int value = rand();
        intArray[i] = value;
        intMirror[i] = value; // value to compare with real Array
    }
    for (int i = 0; i < NBR_VAL; i++)
    {
        const char value = (32 + (rand() % 94));
        charArray[i] = value;
        charMirror[i] = value;
    }
    /***************************************************/
    /*****************Printing Arrays*******************/
    /***************************************************/
    std::cout << "\n>>>NULL<<<" << std::endl; //check with an uninitialized array and trying to access, throw error
    try{
        for (int i = 0; i < NBR_VAL; i++)
            std::cout << intNULL[i] << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }

    std::cout << "\n>>>INT<<<" << std::endl; //access and print an int Array
    for (int i = 0; i < NBR_VAL; i++)
        std::cout << intArray[i] << " | ";
    std::cout << std::endl;

    std::cout << "\n>>>CHAR<<<" << std::endl; //access and print a char Array
    for (int i = 0; i < NBR_VAL; i++)
        std::cout << charArray[i] << " | ";
    std::cout << std::endl;

    std::cout << "\n>>>STRING<<<" << std::endl; //access and print a string Array
    for (int i = 0; i < NBR_VAL; i++)
        std::cout << strArray[i] << " | ";
    std::cout << std::endl;

    std::cout << "\n======Index err======" << std::endl; // giving invalid index to array
    try{
        std::cout << "strArray[200] -> ";
        std::cout << strArray[200] << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::cout << "intArray[-1] -> ";
        std::cout << intArray[-1] << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::cout << "charArray[10] -> ";
        std::cout << charArray[10] << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }

    std::cout << "\n======Index success======" << std::endl;
    try{
        std::cout << "strArray[9] -> "<< strArray[9] << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::cout << "intArray[0] -> "<< intArray[0] << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    try{
        std::cout << "charArray[5] -> " << charArray[5] << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
    std::cout << "\n======Deep copies======" << std::endl;
    std::cout << "\n>>>constructors<<<" << std::endl; // create copies with assignement and copy constructors
    Array<int> intTemp(intArray);
    Array<int> intTmp = intArray;
    Array<std::string> strTemp(strArray);
    Array<std::string> strTmp = strArray;
    std::cout << "---------------" << std::endl;

    //modifying copied array's first element to compare with the original (should not be the same)
    std::cout << "\n>>>INT<<<" << std::endl;
    std::cout << "intArray[0] = " << intArray[0] << " <=> 42" << std::endl;
    intArray[0] = 42;
    std::cout << "intArray[0]-> "<< intArray[0] << std::endl;
    std::cout << "intTemp[0]-> " << intTemp[0] << std::endl;
    std::cout << "intTmp[0]-> " << intTmp[0] << std::endl;

    std::cout << "\n>>>STRING<<<" << std::endl;
    std::cout << "strArray[0] = " << strArray[0] << " <=> \"COPIED HERE\"" << std::endl;
    strArray[0] = "COPIED HERE";
    std::cout << "strArray[0]-> " << strArray[0] << std::endl;
    std::cout << "strTemp[0]-> " << strTemp[0] << std::endl;
    std::cout << "strTmp[0]-> " << strTmp[0] << std::endl;

    std::cout << "\n======MIRROR TEST======" << std::endl; //test my Array template against the real one

    for (int i = 0; i < NBR_VAL; i++)
    {
        if (strArray[i] != strMirror[i])
        {
            std::cerr << strArray[i] << " != " << strMirror[i] << std::endl;
            std::cerr << "didn't save the same value !\n" << std::endl; //modified in Deep copies, should throw error
        }
    }
    for (int i = 0; i < NBR_VAL; i++)
    {
        if (intArray[i] != intMirror[i])
        {
            std::cerr << intArray[i] << " != " << intMirror[i] << std::endl;
            std::cerr << "didn't save the same value !" << std::endl; //modified in Deep copies, should throw error
        }
    }
    for (int i = 0; i < NBR_VAL; i++)
    {
        if (charArray[i] != charMirror[i])
            std::cerr << "didn't save the same value !" << std::endl; //not modified in Deep copies, should throw error
    }

    std::cout << "\n======Destructors======" << std::endl;
    delete [] intMirror;
    delete [] strMirror;
    delete [] charMirror;
    return(0);
}