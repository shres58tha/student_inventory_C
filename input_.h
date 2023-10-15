// useage : input_ ( string to be desplayed for prompt, pointer to data to be saved)
// input_ overloaded
// failed to put it in another file as not sure how to declare template class in h file
// global functions

#ifndef MY_INPUT_H // include guard
#define MY_INPUT_H

#include <iostream>
#include <string>   //for string
#include <iomanip>

#define MAX_CH 50

template< class T_NUM>
void input_( std::string str, T_NUM *p){  // get input  with error checking
        int error;
        do {
            error=0;
            if (std::cin.fail()){ std::cin.clear();  std::cin.ignore(100000000,'\n');}
            std::cout << str;
            std::cin>>*p;
            if (std::cin.peek()!='\n') {std::cin.ignore(100000000,'\n');error=1;}
            else std::cin.ignore();
        }while(std::cin.fail()||error );
}
void input_( std::string str, std::string *p);

void input_( std::string str, char *p, int max_char);

void input_( bool *p);



//#include "input_.cpp"
#endif /* MY_INPUT_H */
