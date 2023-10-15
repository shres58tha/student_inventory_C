/*
 * program that reads the student information like name, address, phone number etc and stores it in a file. capaibilities add, show, edit or delete records from file.
 * object oriented approach used for programming.
 */
#include "student.h"
#include "input_.h"
using namespace std;
int main(){
    student stu;
    char datafile_name[50]="std_record.dat";
   /// datafile_name = ;
    //input_("Enter the data file name",datafile_name);
    stu.set_datafile_name(datafile_name);
    int choice;
    cout<<"***student Record System***";
    while (true){
        cout<<"\nSelect one option below";
        cout<<"\n\t1 => Write Records to file";
        cout<<"\n\t2 => Show all Records From file";
        cout<<"\n\t3 => Show One Recor";
        cout<<"\n\t4 => Edit a Record";
        cout<<"\n\t5 => Delete a Record";
        cout<<"\n\t6 => Exit from Program";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)	{
            case 1:
                stu.write_rec();
                break;
            case 2:
                stu.readall_rec();
                break;
            case 3:
                stu.readone_rec();
                break;
            case 4:
                stu.edit_rec();
                break;
            case 5:
                stu.delete_rec();
                break;
            case 6:
                exit(0);
                break;
                default:
                cout<<"\nChoice not available";
                exit (0);
        }
    }
    return 0;
}
