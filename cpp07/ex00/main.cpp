
#include "./includes/whatever.hpp"

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

// int main()
// {
//     int         int_x = -12;
//     int         int_y = -42;
//     double      dbl_x = 0.12;
//     double      dbl_y = 0.42;
//     const int   cst_x = 20;
//     const int   cst_y = 10;
//     char        car_x = 'A';
//     char        car_y = 'a';
//     std::string str_x = "Hello";
//     std::string str_y = "World";
    
//     std::cout << "=======MAX=======" << std::endl;

//     std::cout << "\n---INT type---" << std::endl;
//     std::cout << "x = " << int_x << " && y = " << int_y
//     << " // Max -> " << max<int>(&int_x, &int_y) << std::endl;

//     std::cout << "\n---DOUBLE type---" << std::endl;
//     std::cout << "x = " << dbl_x << " && y = " << dbl_y
//     << " // Max -> " << max<double>(&dbl_y, &dbl_x) << std::endl;

//     std::cout << "\n---CHAR type---" << std::endl;
//     std::cout << "x = " << car_x << " && y = " << car_y
//     << " // Max -> " << max<char>(&car_x, &car_y) << std::endl;

//     std::cout << "\n---const INT type---" << std::endl;
//     std::cout << "x = " << cst_x << " && y = " << cst_y
//     << " // Max -> " << max<const int>(&cst_x, &cst_y) << std::endl;

// ////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////

//     std::cout << "\n=======Min=======" << std::endl;

//     std::cout << "\n---INT type---" << std::endl;
//     std::cout << "x = " << int_x << " && y = " << int_y
//     << " // Min -> " << min<int>(int_x, int_y) << std::endl;

//     std::cout << "\n---DOUBLE type---" << std::endl;
//     std::cout << "x = " << dbl_x << " && y = " << dbl_y
//     << " // Min -> " << min<double>(dbl_x, dbl_y) << std::endl;

//     std::cout << "\n---CHAR type---" << std::endl;
//     std::cout << "x = " << car_x << " && y = " << car_y
//     << " // Min -> " << min<char>(car_x, car_y) << std::endl;

//     std::cout << "\n---const INT type---" << std::endl;
//     std::cout << "x = " << cst_x << " && y = " << cst_y
//     << " // Min -> " << min<const int>(&cst_x, &cst_y) << std::endl;

// ////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////

//     std::cout << "\n=======SWAP=======" << std::endl;

//     std::cout << "\n---INT type---" << std::endl;
//     std::cout << "Before swap: " << std::endl;
//     std::cout << "x = " << int_x << std::endl
//     << "y = " << int_y << std::endl;
//     swap<int>(&int_x, &int_y);
//     std::cout << "After swap: " << std::endl;
//     std::cout << "x = " << int_x << std::endl
//     << "y = " << int_y << std::endl;

//     std::cout << "\n---DOUBLE type---" << std::endl;
//     std::cout << "Before swap: " << std::endl;
//     std::cout << "x = " << dbl_x << std::endl
//     << "y = " << dbl_y << std::endl;
//     swap<double>(dbl_x, dbl_y);
//     std::cout << "After swap: " << std::endl;
//     std::cout << "x = " << dbl_x << std::endl
//     << "y = " << dbl_y << std::endl;

//     std::cout << "\n---STRING type---" << std::endl;
//     std::cout << "Before swap: " << std::endl;
//     std::cout << "x = " << str_x << std::endl
//     << "y = " << str_y << std::endl;
//     swap<std::string>(&str_x, &str_y);
//     std::cout << "After swap: " << std::endl;
//     std::cout << "x = " << str_x << std::endl
//     << "y = " << str_y << std::endl;
//     // std::cout << "\n---STRING type---" << std::endl;
//     // std::cout << "Before swap: " << std::endl;
//     // std::cout << "x = " << str_x << std::endl
//     // << "y = " << str_y << std::endl;
//     // ::swap<std::string>(str_x, str_y);
//     // std::cout << "After swap: " << std::endl;
//     // std::cout << "x = " << str_x << std::endl
//     // << "y = " << str_y << std::endl;
//     return (0);
// }