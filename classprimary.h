#ifndef classprimary
#define classprimary

#include "baseclass.h"

class primary:public classes                  // Class for Primary Students
{
    int hin,eng,mat,evs;

    public:
    void view();
    void getdata();
    char isfail();
};

//*******************************************************
// CLASS DEFINITIONS
//*******************************************************

void primary::view()
{
    std::cout<<"\n\nStudent's name:"<<name
    <<"\nRoll No:"<<rollno
    <<"\n\nMarks in-"
    <<"\nEnglish:"<<eng
    <<"\nHindi:"<<hin
    <<"\nMaths:"<<mat
    <<"\nEVS:"<<evs
    <<"\n\nPercentage:"<<per;
}

void primary::getdata()
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
    cout<<"\nEVS:";
    cin>>evs;

    total=eng+hin+mat+evs;
    per=total/4;
}


char primary::isfail()              //To check if the student has failed
{
    failed='n';
    if((hin<33)||(eng<33)||(mat<33)||(evs<33))
    failed='y';
    return(failed);
}

#endif