#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include<fstream>
#include <string>
#include <cstring>
#include "input_.h"
#include "account.h"

using namespace std;
  // name of the data file
//class derived-class: access-specifier base-class

class employee: public account {    // student object with all in one, use the global input_ for auto error handling
private:
    char name[MAX_CH], add[MAX_CH],phone[MAX_CH];
    char datafile[MAX_CH];
public:
    void set_datafile_name(char *name);
    void read_data();
    void show_data();
    void write_rec();
    void readone_rec();
    void readall_rec();
    void edit_rec();
    void delete_rec();
};              // end of student class


#endif // STUDENT_H_INCLUDED

#endif // EMPLOYEE_H
