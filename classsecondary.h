#ifndef classsecondary
#define classsecondary

#include "baseclass.h"

class secondary:public classes          // Class for Secondary Students
{
    int hin,eng,mat,sst,sci,sans;
    
    public:
    void view();
    void getdata();
    char isfail();
};

//*******************************************************
// CLASS DEFINITIONS
//*******************************************************

void secondary::view()
{
    std::cout<<"\n\nStudent's name:"<<name
    <<"\nRoll No:"<<rollno
    <<"\n\nMarks in-"
    <<"\nEnglish:"<<eng
    <<"\nHindi:"<<hin
    <<"\nMaths:"<<mat
    <<"\nSSt:"<<sst
    <<"\nScience:"<<sci
    <<"\nSanskrit:"<<sans
    <<"\n\nPercentage:"<<per;
}

void secondary::getdata()
{
    using namespace std;
    
    cout<<" ***** ENTER STUDENT INFORMATION *****\n\n";
    cout<<"Student's name:";
    cin>>name;
    cout<<"\nRoll No:";
    cin>>rollno;

    cout<<"\n\nMarks in-";
    cout<<"\nEnglish:";
    cin>>eng;
    cout<<"\nHindi:";
    cin>>hin;
    cout<<"\nMaths:";
    cin>>mat;
    cout<<"\nSSt:";
    cin>>sst;
    cout<<"\nScience:";
    cin>>sci;
    cout<<"\nSanskrit:";
    cin>>sans;
    total=eng+hin+mat+sst+sci+sans;
    per=total/6;
}

char secondary::isfail()            //To check if the student has failed
{
    failed='n';
    if((hin<33)||(eng<33)||(mat<33)||(sst<33)||(sci<33)||(sans<33))
    failed='y';
    return(failed);
}

#endif