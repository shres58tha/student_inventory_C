#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include<iostream>
#include<fstream>
#include <string>
#include <cstring>
#include "input_.h"
#define MAX_CH 50

using namespace std;
  // name of the data file

class student {    // student object with all in one, use the global input_ for auto error handling
private:
    char datafile[MAX_CH];
    char name[MAX_CH], add[MAX_CH],phone[MAX_CH];

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
