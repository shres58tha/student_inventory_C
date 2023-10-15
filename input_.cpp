// useage : input_ ( string to be desplayed for prompt, pointer to data to be saved)
// input_ overloaded
// failed to put it in another file as not sure how to declare template class in h file
// global functions

#include "input_.h"

#include <cstring>
using namespace std;

void input_( std::string str, std::string *p){  // input string to string pointer  // template overloaded
        do{
            if (std::cin.fail()){ std::cin.clear(); while (std::cin.ignore(100000000,'\n'));}
            std::cout << str ;      // prompt
            while ( std::cin.peek() == '\n') std::cin.ignore();
            std::getline(std::cin,*p);   // does not leave dangling anything in the input stream
        }while(std::cin.fail() || p->empty());
}

void input_( std::string str, char *p, int max_char){
        char *handle;
        handle=p;
        std::string temp;
        input_( str, &temp);
        if (temp.length() >=max_char){
            std::cout<<"buffer overflow error the entered text will be truncated"<<std::endl;
        }
        strncpy( p, temp.c_str(), max_char);
        //strcpy(char_array, s.c_str());
}


void input_( bool *p){   // template overloaded
        char ch;
        int bad_input;
        do {           // get input  with error checking
            bad_input=0;
            if (std::cin.fail()){ std::cin.clear();  std::cin.ignore(100000000,'\n');}
            std::cout << "Enter 'y' for true and 'n' for false : ";
            std::cin>>ch;
            ch =std::tolower(ch);
            if ( std::cin.peek() != '\n' )
               { std::cin.ignore(100000, '\n');  bad_input=1;}
            else
                std::cin.ignore();// remove the '/n' from in stream for the next scanning
            if (ch == 'y') *p=1;
            else if (ch == 'n') *p=0;
            else bad_input=1;

        }while(bad_input);
}

