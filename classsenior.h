#ifndef classsenior
#define classsenior

#include "baseclass.h"

class senior:public classes         // Class for Senior Students
{
    int phy,chem,mat,eng,cs;
    
    public:
    void view();
    void getdata();
    char isfail();
};

//*******************************************************
// CLASS DEFINITIONS
//*******************************************************

void senior::view()
{
    std::cout<<"\n\nStudent's name:"<<name
    <<"\nRoll No:"<<rollno
    <<"\n\nMarks in-"
    <<"\nEnglish:"<<eng
    <<"\nPhysics:"<<phy
    <<"\nChemistry:"<<chem
    <<"\nMaths:"<<mat
    <<"\nCS:"<<cs
    <<"\n\nPercentage:"<<per;
}

void senior::getdata()
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
    cout<<"\nPhysics:";
    cin>>phy;
    cout<<"\nChemistry:";
    cin>>chem;
    cout<<"\nMaths:";
    cin>>mat;
    cout<<"\nCS:";
    cin>>cs;

    total=eng+phy+mat+chem+cs;
    per=total/5;
}

char senior::isfail()           //To check if the student has failed
{
    failed='n';
    if((phy<33)||(chem<33)||(mat<33)||(eng<33)||(cs<33))
    failed='y';
    return(failed);
}

#endif