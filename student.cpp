
#include "student.h"
void student::set_datafile_name(char *name){
    strcpy (datafile,name);
}

void student::read_data(){
    input_("\nEnter name: ", name, MAX_CH);
    input_("\nEnter address: ", add, MAX_CH);
    input_("Enter phone number: ",phone, MAX_CH);
}

void student::show_data(){
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<add<<endl;
    cout<<"Phone number: "<<phone<<endl;
    cout<<"\n\n------------------------------"<<endl;
}

void student::write_rec(){
    ofstream outfile(datafile, ios::binary | ios::app);  // datafile in append mode
    read_data();
    outfile .write(reinterpret_cast<char*>(this), sizeof(*this));
}

void student::readall_rec(){
    ifstream infile (datafile, ios::binary);      // opening file
    infile.seekg(0, ios::beg);
    if(!infile){
        cout<<"file not found: store record first"<<endl;
        return;
    }
    cout<<"\n\t*** Data from file ***\n"<<endl;
    while( !infile.eof() ) {
        if ( (bool)(infile.read (reinterpret_cast<char*>(this), sizeof(*this)) )>0) {
            show_data();
            }
    }
}

void student::readone_rec(){
    int n;

    ifstream infile(datafile, ios::binary);             // opening file
    if(!infile){
        cout<<"file not found: store record first"<<endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count=infile.tellg()/sizeof(*this);
    cout<<"\nThere are "<<count<<" records in the file";
    cout<<"\nEnter Record Number: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this) );
    show_data();
}

void student::edit_rec(){
    int n;
    fstream iofile(datafile, ios::in|ios::binary);     // mode write
    if(!iofile) {
        cout<<"file not found: store record first"<<endl;
        return;
    }

    iofile.seekg(0, ios::end) ;

    int count=iofile.tellg()/sizeof(*this);  // number of records in the file

    cout<<"\nThere are "<<count<<" records in the file";
    cout<<"\nEnter Record Number to be edited: ";       // can be vastly improved here
                                                        // possible bug screen overflow
                                                        // add search by name and or student _id_
    cin>>n;

    iofile.seekg( (n-1)*sizeof(*this) );
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this) );

    cout<<"Record "<<n<<"has following data"<<endl;
    show_data();
    iofile.close();

    iofile.open(datafile, ios::out|ios::out|ios::binary);
                                                    // read write mode
                                                    //ios::out alone caused file to be over written so
                                                    //ios::in is used along with ios::out
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"Enter data to modify"<<endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this) );
}


void student::delete_rec(){
    int n;
    char tempfile[]="temp.dat";                        // temp file so data - deleted record

    ifstream infile (datafile, ios::binary);
    if(!infile){
        cout<<"file not found: store record first"<<endl;
        return;
    }
    infile.seekg (0, ios::end);
    int count=infile.tellg ()/sizeof(*this);

    cout<<"\nThere are "<<count<<"records in the file";
    cout<<"\nEnter Record Number to be deleted:";
    cin>>n;
    fstream tmpfile(tempfile, ios::out|ios::binary);
                                                        //ios::out is used to create the file
    infile.seekg(0);
    for(int i=0;i<count;++i){
        infile.read( reinterpret_cast<char*>(this), sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();

    ofstream outfile (datafile, ios::binary);              //copying data from temp to datafile
    tmpfile.close();

    tmpfile.open(tempfile, ios::in|ios::binary);

    for(int i=0;i<count-1;++i){
        tmpfile.read(reinterpret_cast<char*>(this), sizeof(*this));
        outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    tmpfile.close();
    remove (tempfile);
}



