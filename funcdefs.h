#ifndef funcdefs
#define funcdefs

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include "globalvars.h"

//*******************************************************
// FUNCTION PROTOTYPES
//*******************************************************
void header();
void footer();
void password();
void enter();
void modify_record();
void del_menu();
void view_menu();
void del_record();
void del_class();
void view_student();
void view_class();
void viewstat_class();
void viewstat_school();
int fail_class(int);
void fail_school();
void fail_record(int);
void highest_class(int);
void highest_school();
double passper_class(int);
void passper_school();
void sort_file(int);

//*******************************************************
// FUNCTION DEFINITIONS
//*******************************************************

void enter() //1
{

    using namespace std;

    cout<<" ***** CREATE A RECORD *****";
    int std,n;
    cout<<"\n\nEnter class of student (1-12):";
    start:
    cin>>std;

    if((std>12)||(std<=0))
    {
        cout<<"\nSorry! Wrong input\nPlease re-enter the class:";
        goto start;
    }

    fs.open(rec_file[std],ios::app);
    cout<<"\nHow many records would you like to create?";
    cin>>n;
    
    while(n)
    { switch(std)
        {
            case 1:pri_class[1].getdata();
            fs.write((char*)&pri_class[1],sizeof(primary));
            break;
            case 2:pri_class[2].getdata();
            fs.write((char*)&pri_class[2],sizeof(primary));
            break;
            case 3:pri_class[3].getdata();
            fs.write((char*)&pri_class[3],sizeof(primary));
            break;
            case 4:pri_class[4].getdata();
            fs.write((char*)&pri_class[4],sizeof(primary));
            break;
            case 5:pri_class[5].getdata();
            fs.write((char*)&pri_class[5],sizeof(primary));
            break;
            case 6:sec_class[6].getdata();
            fs.write((char*)&sec_class[6],sizeof(secondary));
            break;
            case 7:sec_class[7].getdata();
            fs.write((char*)&sec_class[7],sizeof(secondary));
            break;

            case 8:sec_class[8].getdata();
            fs.write((char*)&sec_class[8],sizeof(secondary));
            break;
            case 9:sec_class[9].getdata();
            fs.write((char*)&sec_class[9],sizeof(secondary));
            break;
            case 10:sec_class[10].getdata();
            fs.write((char*)&sec_class[10],sizeof(secondary));
            break;
            case 11:sen_class[11].getdata();
            fs.write((char*)&sen_class[11],sizeof(senior));
            break;
            case 12:sen_class[12].getdata();
            fs.write((char*)&sen_class[12],sizeof(senior));
            break;
            default:cout<<"Sorry! Wrong input";
        }
        n--;
    }
    sort_file(std);
}

void modify_record() //2
{
    using namespace std;
    
    int std,rollno,n;
    fstream fo;

    cout<<" ***** MODIFY A RECORD *****\n\n";
    cout<<"Enter Class of record you want to modify:";
    cin>>std;
    cout<<"\nHow many records do you want to modify?";
    cin>>n;

    while(n)
    {
        cout<<" ***** MODIFY A RECORD *****\n\n";
        cout<<"Enter Roll No of record you want to modify:";
        cin>>rollno;

        int found='n';
        fs.open(rec_file[std],ios::in);
        fo.open("temp.dat",ios::out);
        if(std>10)
        {
            fs.read((char*)&sen_class[std],sizeof(senior));
        
            while(fs)
            {
                if(sen_class[std].getrno()==rollno)
                {
                    found='y';
                    cout<<"\n\nCurrent record of student is:";
                    sen_class[std].view();

                    cout<<"\n\nPlease enter new information";
                    sen_class[std].getdata();
                }
                fo.write((char*)&sen_class[std],sizeof(senior));
                fs.read((char*)&sen_class[std],sizeof(senior));
            }
        }
        
        else if(std>5)
        {
            fs.read((char*)&sec_class[std],sizeof(secondary));
            while(fs)
            {
                if(sec_class[std].getrno()==rollno)
                {
                    found='y';
                    cout<<"\n\nCurrent record of student is:";
                    sec_class[std].view();

                    cout<<"\n\nPlease enter new information";
                    sec_class[std].getdata();
                }

                fo.write((char*)&sec_class[std],sizeof(secondary));
                fs.read((char*)&sec_class[std],sizeof(secondary));
            }
        }
        
        else
        {
            fs.read((char*)&pri_class[std],sizeof(primary));
            while(fs)
            {
                if(pri_class[std].getrno()==rollno)
                {
                    found='y';
                    cout<<"\n\nCurrent record of student is:";
                    pri_class[std].view();

                    cout<<"\n\nPlease enter new information";
                    pri_class[std].getdata();
                }
                
                fo.write((char*)&pri_class[std],sizeof(primary));
                fs.read((char*)&pri_class[std],sizeof(primary));
            }
        }
        fo.close();
        fs.close();
        remove(rec_file[std]);
        rename("temp.dat",rec_file[std]);

        if(found=='n')
        { 
            cout<<"Sorry! Record not found";

        }
        n--;
    }
}

void del_menu() //3
{
    do
    {

        int choice,std;
        std::cout<<" ***** DELETE MENU ***** "
        <<"\n\n1 Record of a particular student"
        <<"\n2 Record of a whole class"
        <<"\n3 Back to Main Menu\n\n";
        std::cin>>choice;
        
        switch(choice)
        {
            case 1:del_record();
            break;
            case 2:del_class();
            break;
            case 3:return;
            default:std::cout<<"Sorry! Wrong input";

        }
    }while(1);
}

void view_menu() //4
{
    do
    {

        int choice,std;
        std::cout<<" ***** VIEW MENU ***** "
        <<"\n\n1 Record of a particular student"
        <<"\n2 Record of all students of a particular class"
        <<"\n3 Statistics of a particular class"
        <<"\n4 Statistics of the whole school"
        <<"\n5 Back to Main Menu\n\n";
        std::cin>>choice;

        switch(choice)
        {
            case 1:view_student();
            break;
            case 2:view_class();
            break;
            case 3:viewstat_class();
            break;
            case 4:viewstat_school();
            break;
            case 5:return;
            default:std::cout<<"Sorry! Wrong input";

        }
    }while(1);
}

void del_record() //5
{
    using namespace std;

    cout<<" ***** DELETE RECORD OF A STUDENT*****";
    int std,n;
    cout<<"\n\nEnter class of student (1-12):";
    
    start:
    cin>>std;
    if((std>12)||(std<0))
    {
        cout<<"Sorry! Wrong input\nPlease re-enter the class:";
        goto start;
    }
    cout<<"\nHow many records would you like to delete?";
    cin>>n;
    fstream fo;
    
    while(n)
    {

        cout<<" ***** DELETE A RECORD *****\n\n";
        fs.open(rec_file[std],ios::in);
        fo.open("temp.dat",ios::out);

        int rno;
        cout<<"Enter Roll No of Student whose record is to be deleted:";
        cin>>rno;
        char confirm='n',found='n';
        
        if(std>10)
        {
            fs.read((char*)&sen_class[std],sizeof(senior));
            
            while(fs)
            {
                if(sen_class[std].getrno()==rno)
                {
                    found='y';
                    sen_class[std].view();
                    cout<<"\n\nAre you sure you want to Delete?";
                    cin>>confirm;
                    if(confirm=='n')
                    fo.write((char*)&sen_class[std],sizeof(senior));
                    else cout<<"\n\nRecord has been Deleted";
                }
                else fo.write((char*)&sen_class[std],sizeof(senior));
                
                fs.read((char*)&sen_class[std],sizeof(senior));
            }
        }

        else if(std>5)
        {
            fs.read((char*)&sec_class[std],sizeof(secondary));
            while(fs)
            {
                if(sec_class[std].getrno()==rno)
                {
                    found='y';
                    sec_class[std].view();
                    cout<<"\n\nAre you sure you want to Delete?";
                    cin>>confirm;
                    if(confirm=='n')
                    fo.write((char*)&sec_class[std],sizeof(secondary));
                    else cout<<"\n\nRecord has been Deleted";
                }

                else fo.write((char*)&sec_class[std],sizeof(secondary));
                
                fs.read((char*)&sec_class[std],sizeof(secondary));
            }
        }

        else
        {
            fs.read((char*)&pri_class[std],sizeof(primary));
            while(fs)
            {
                if(pri_class[std].getrno()==rno)
                {
                    found='y';
                    pri_class[std].view();
                    cout<<"\n\nAre you sure you want to Delete?";
                    cin>>confirm;
                    if(confirm=='n')
                    fo.write((char*)&pri_class[std],sizeof(primary));
                    else cout<<"\n\nRecord has been Deleted";
                }
                else fo.write((char*)&pri_class[std],sizeof(primary));
                
                fs.read((char*)&pri_class[std],sizeof(primary));
            }
        }

        fo.close();
        fs.close();
        remove(rec_file[std]);
        rename("temp.dat",rec_file[std]);
        if(found=='n')
        cout<<"Sorry! Record not found. Please try again";
        n--;

    }
}

void del_class() //6
{

    using namespace std;

    int n,std;
    cout<<"\n\nHow many classes would you like to remove?";
    cin>>n;
    while(n)
    {

        cout<<" ***** DELETE RECORD OF A CLASS *****";
        cout<<"\nEnter class:";
        start:
        cin>>std;
        
        if((std>12)||(std<0))
        {
            cout<<"Sorry! Wrong input\nPlease re-enter the class:";
            goto start;
        }

        char confirm='n';
        cout<<"Are you sure you want to Delete all Records of Class "
        <<std<<"?";
        cin>>confirm;
        
        if(confirm=='y')
        {
            remove(rec_file[std]);
            cout<<"\nRecord has been deleted";

        }
        n--;
    }
}

void view_student() //7
{
    using namespace std;

    int std,rno;
    char found='n';
    cout<<"Enter class:";

    start:

    cin>>std;
    if((std>12)||(std<=0))
    {
        cout<<"\nSorry! Wrong input\nPlease re-enter the class:";
        goto start;
    }
    fs.open(rec_file[std],ios::in);
    cout<<"\nEnter Roll No:";
    cin>>rno;
    fs.clear();
    fs.seekg(0,ios::beg);
    if(std>10)
    {
        fs.read((char*)&sen_class[std],sizeof(senior));
        while(fs)
        {
            if(sen_class[std].getrno()==rno)
            { 
                found='y';
                cout<<" ***** RECORD OF ";
                sen_class[std].givename();
                cout<<" *****\n\n";
                sen_class[std].view();
            }
            fs.read((char*)&sen_class[std],sizeof(senior));
        }
    }
    else if(std>5)
    {
        fs.read((char*)&sec_class[std],sizeof(secondary));

        while(fs)
        {
            if(sec_class[std].getrno()==rno)
            { 
                found='y';
                cout<<" ***** RECORD OF ";
                sec_class[std].givename();
                cout<<" *****\n\n";
                sec_class[std].view();
            }
            fs.read((char*)&sec_class[std],sizeof(secondary));
        }
    }
    else
    {
        fs.read((char*)&pri_class[std],sizeof(primary));
        while(fs)
        {
            if(pri_class[std].getrno()==rno)
            { 
                found='y';
                cout<<" ***** RECORD OF ";
                pri_class[std].givename();
                cout<<" *****\n\n";
                pri_class[std].view();
            }
            fs.read((char*)&pri_class[std],sizeof(primary));
        }
    }
    if(found=='n') cout<<"\nSorry! Record not found";
    fs.close();

}

void view_class() //8
{
    using namespace std;

    int std;
    char found='n';
    cout<<"Enter class:";
    start:
    cin>>std;
    
    if((std>12)||(std<0))
    {
        cout<<"\nSorry! Wrong input\nPlease re-enter the class:";
        goto start;
    }
    fs.open(rec_file[std],ios::in);
    fs.clear();
    fs.seekg(0,ios::beg);
    if(std>10)
    { 
        fs.read((char*)&sen_class[std],sizeof(senior));
        while(fs)
        {
            found='y';
            cout<<" *** RECORD OF ALL STUDENTS OF CLASS "<<std<<" ***\n\n";
            sen_class[std].view();

            fs.read((char*)&sen_class[std],sizeof(senior));
        }
    }
    else if(std>5)
    {
        fs.read((char*)&sec_class[std],sizeof(secondary));
        while(fs)
        { 
            found='y';
            cout<<"*** RECORD OF ALL STUDENTS OF CLASS "<<std<<" ***\n\n";
            sec_class[std].view();

            fs.read((char*)&sec_class[std],sizeof(secondary));
        }
    }

    else
    {
        fs.read((char*)&pri_class[std],sizeof(primary));
        while(fs)
        {

            found='y';
            cout<<" *** RECORD OF ALL STUDENTS OF CLASS "<<std<<" ***\n\n";
            pri_class[std].view();

            fs.read((char*)&pri_class[std],sizeof(primary));
        }
    }
    if(found=='n') cout<<"\nSorry! Records of Class "<<std<<" do not exist";
    fs.close();

}

void viewstat_class() //9
{
    using namespace std;

    cout<<"Enter class:";
    
    start:
    
    int std;
    cin>>std;
    if((std>12)||(std<0))
    {
        cout<<"\nSorry! Wrong input\nPlease re-enter the class:";
        goto start;
    }
    do
    {

        cout<<" ***** STATISTICS OF CLASS "<<std<<" *****\n\n"
        <<"\n1 Topper of class"
        <<"\n2 Number of students who failed"
        <<"\n3 Record of students who failed"
        <<"\n4 Pass Percentage of class"
        <<"\n5 Return to View Menu\n\n";

        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:highest_class(std);
            break;
            case 2:
            cout<<"**NUMBER OF STUDENTS WHO FAILED IN A CLASS **\n\n"
            <<"Class "<<std<<":"<<fail_class(std);

            break;
            case 3:fail_record(std);
            break;
            case 4:
            cout<<" ***** PASS PERCENTAGE OF A CLASS *****\n\n"
            <<"Class "<<std<<":"<<passper_class(std);

            break;
            case 5:return;
        }
    }while(1);
}

void viewstat_school() //10
{
    do
    {

        std::cout<<" ***** STATISTICS OF SCHOOL *****\n\n";
        std::cout<<"What would you like to view?"
        <<"\n1 Toppers of each class"
        <<"\n2 Number of students who failed in each class"
        <<"\n3 Total Number of students who failed in the school"
        <<"\n4 Pass Percentage of school"
        <<"\n5 Return to View Menu\n\n";
        int choice;
        std::cin>>choice;

        switch(choice)
        {
            case 1:highest_school();
            break;
            case 2:
                std::cout<<"**NUMBER OF STUDENTS WHO FAILED PER CLASS **\n\n";
                for(int i=1;i<=12;i++)
                {
                    std::cout<<"Class "<<i<<":"
                    <<fail_class(i)<<std::endl;
                };
            break;

            case 3:fail_school();
            break;
            case 4:passper_school();
            break;
            case 5:return;
        }
    }while(1);
}

int fail_class(int std) //11
{
    fs.open(rec_file[std],std::ios::in);
    int fail=0;
    if(std>10)
    {
        fs.read((char*)&sen_class[std],sizeof(senior));
        while(fs)
        {
            if(sen_class[std].isfail()=='y')
            fail++;
            fs.read((char*)&sen_class[std],sizeof(senior));
        }
    }
    
    else if(std>5)
    {
        fs.read((char*)&sec_class[std],sizeof(secondary));

        while(fs)
        {
            if(sec_class[std].isfail()=='y')
            fail++;
            fs.read((char*)&sec_class[std],sizeof(secondary));
        }
    }
    else
    {
        fs.read((char*)&pri_class[std],sizeof(primary));
        while(fs)
        {
            if(pri_class[std].isfail()=='y')
            fail++;
            fs.read((char*)&pri_class[std],sizeof(primary));
        }
    }
    fs.close();
    return(fail);
}

void fail_school() //12
{

    int total_fail=0;
    for(int i=1;i<=12;i++)
    total_fail+=fail_class(i);
    std::cout<<" ***** TOTAL STUDENTS FAILED IN SCHOOL *****\n\n"
    <<"Number of students who failed:"<<total_fail;

}

void fail_record(int std) //13
{
    fs.open(rec_file[std],std::ios::in);
    char found='n';
    if(std>10)
    {
        fs.read((char*)&sen_class[std],sizeof(senior));
        while(fs)
        {
            if(sen_class[std].isfail()=='y')
            { 
            found='y';
            std::cout<<"** RECORD OF STUDENTS WHO FAILED IN CLASS "<<std<<"**";
            sen_class[std].view();

            }
            fs.read((char*)&sen_class[std],sizeof(senior));
        }
    }
    else if(std>5)
    {
        fs.read((char*)&sec_class[std],sizeof(secondary));
        while(fs)
        {
            if(sec_class[std].isfail()=='y')
            {
                found='y';
                std::cout<<"** RECORD OF STUDENTS WHO FAILED IN CLASS "<<std<<"**";
                sec_class[std].view();

            }
            fs.read((char*)&sec_class[std],sizeof(secondary));
        }
    }
    else
    {
        fs.read((char*)&pri_class[std],sizeof(primary));
        while(fs)
        {
            if(pri_class[std].isfail()=='y')
            { 
                found='y';
                std::cout<<"** RECORD OF STUDENTS WHO FAILED IN CLASS "<<std<<"**";
                pri_class[std].view();

            }
            fs.read((char*)&pri_class[std],sizeof(primary));
        }
    }
    if(found=='n')
    {
        std::cout<<"\nNo student failed in class "<<std;
    }
    fs.close();
}

void highest_class(int std) //14
{
    using namespace std;

    cout<<" ***** TOPPER OF CLASS "<<std<<" *****\n\n";
    int highest=0;
    fs.open(rec_file[std],ios::in);
    if(std>10)
    {
        fs.read((char*)&sen_class[std],sizeof(senior));
        while(fs)
        {
            if(sen_class[std].gettotal()>highest)
            highest=sen_class[std].gettotal();
            fs.read((char*)&sen_class[std],sizeof(senior));
        }
        fs.clear();
        fs.seekg(0,ios::beg);
        fs.read((char*)&sen_class[std],sizeof(senior));
        while(fs)
        {
            if(sen_class[std].gettotal()==highest)
            {
                cout<<"Highest Marks in Class "<<std<<" are:"<<highest
                <<"\n\nDetails of topper:";
                sen_class[std].view();
            }


            fs.read((char*)&sen_class[std],sizeof(senior));
        }
    }
    else if(std>5)
    {
        fs.read((char*)&sec_class[std],sizeof(secondary));
        while(fs)
        {
            if(sec_class[std].gettotal()>highest)
            highest=sec_class[std].gettotal();
            fs.read((char*)&sec_class[std],sizeof(secondary));
        }
        fs.clear();
        fs.seekg(0,ios::beg);
        fs.read((char*)&sec_class[std],sizeof(secondary));
        while(fs)
        {
            if(sec_class[std].gettotal()==highest)
            {
                cout<<"Highest Marks in Class "<<std<<" are:"<<highest
                <<"\n\nDetails of topper:";
                sec_class[std].view();
            }
            fs.read((char*)&sec_class[std],sizeof(secondary));
        }
    }
    else
    {
        fs.read((char*)&pri_class[std],sizeof(primary));
        while(fs)
        {
            if(pri_class[std].gettotal()>highest)
            highest=pri_class[std].gettotal();
            fs.read((char*)&pri_class[std],sizeof(primary));
        }
        fs.clear();
        fs.seekg(0,ios::beg);
        fs.read((char*)&pri_class[std],sizeof(primary));


        while(fs)
        {
            if(pri_class[std].gettotal()==highest)
            {
                cout<<"Highest Marks in Class "<<std<<" are:"<<highest
                <<"\n\nDetails of topper:";
                pri_class[std].view();
            }
            fs.read((char*)&pri_class[std],sizeof(primary));
        }
    }

    fs.close();
}

void highest_school() //15
{
    for(int i=1;i<=12;i++)
    highest_class(i);
}

double passper_class(int std) //16
{
    fs.open(rec_file[std],std::ios::in);
    int total=0,fail=0;
    if(std>10)
    {
        fs.read((char*)&sen_class[std],sizeof(senior));
        while(fs)
        {
            if(sen_class[std].isfail()=='y')
            fail++;
            fs.read((char*)&sen_class[std],sizeof(senior));
            total++;
        }
    }


    else if(std>5)
    {
        fs.read((char*)&sec_class[std],sizeof(secondary));
        while(fs)
        {
            if(sec_class[std].isfail()=='y')
            fail++;
            fs.read((char*)&sec_class[std],sizeof(secondary));
            total++;
        }
    }
    else
    {
        fs.read((char*)&pri_class[std],sizeof(primary));
        while(fs)
        {
            if(pri_class[std].isfail()=='y')
            fail++;
            fs.read((char*)&pri_class[std],sizeof(primary));
            total++;
        }
    }
    fs.close();
    double passper=0;
    passper=(double)fail/total;

    passper=(1-passper)*100;
    return(passper);
}

void passper_school() //17
{

    double passper=0;

    for(int i=1;i<=12;i++)
    passper+=passper_class(i);
    passper=passper/12;
    std::cout<<" ***** PASS PERCENTAGE OF SCHOOL *****"
    <<std::endl<<std::endl
    <<"Pass Percentage:"<<passper;

}

void sort_file(int std) //18
{                               //This function is required to keep the records of each file always sorted in order of roll number

    std::fstream fo;
    fo.open("temp.dat",std::ios::out);
    fs.close();
    fs.open(rec_file[std],std::ios::in);
    int min_rno=1000,last_rno=0;
    if(std>10)
    {
        fs.read((char*)&sen_class[std],sizeof(senior));
        while(fs)
        {
            if(sen_class[std].getrno()>last_rno)
                last_rno=sen_class[std].getrno();
            if(sen_class[std].getrno()<min_rno)
                min_rno=sen_class[std].getrno();
            fs.read((char*)&sen_class[std],sizeof(senior));
        }
        while(min_rno<=last_rno)
        {
            fs.clear();
            fs.seekg(0,std::ios::beg);
            fs.read((char*)&sen_class[std],sizeof(senior));
            int check=min_rno;


            while(fs)
            {
                if(sen_class[std].getrno()==min_rno)
                {
                    fo.write((char*)&sen_class[std],sizeof(senior));
                    min_rno=min_rno+1;
                }
                fs.read((char*)&sen_class[std],sizeof(senior));
            }
            if(min_rno==check)
                min_rno++;
        }
    }

    else if(std>5)
    {
        fs.read((char*)&sec_class[std],sizeof(secondary));
        while(fs)
        {
            if(sec_class[std].getrno()>last_rno)
                last_rno=sec_class[std].getrno();
            if(sec_class[std].getrno()<min_rno)
                min_rno=sec_class[std].getrno();
            fs.read((char*)&sec_class[std],sizeof(secondary));
        }
        while(min_rno<=last_rno)
        {
            fs.clear();
            fs.seekg(0,std::ios::beg);
            fs.read((char*)&sec_class[std],sizeof(secondary));
            int check=min_rno;

            while(fs)
            {
                if(sec_class[std].getrno()==min_rno)
                {
                    fo.write((char*)&sec_class[std],sizeof(secondary));
                    min_rno=min_rno+1;
                }


                fs.read((char*)&sec_class[std],sizeof(secondary));
            }

            if(min_rno==check)
            min_rno++;
        }
    }
    else
    {
        fs.read((char*)&pri_class[std],sizeof(primary));
        while(fs)
        {
            if(pri_class[std].getrno()>last_rno)
                last_rno=pri_class[std].getrno();
            if(pri_class[std].getrno()<min_rno)
                min_rno=pri_class[std].getrno();
            fs.read((char*)&pri_class[std],sizeof(primary));
        }
        while(min_rno<=last_rno)
        {
            fs.clear();
            fs.seekg(0,std::ios::beg);
            fs.read((char*)&pri_class[std],sizeof(primary));
            int check=min_rno;
            while(fs)
            {
                if(pri_class[std].getrno()==min_rno)
                {
                    fo.write((char*)&pri_class[std],sizeof(primary));
                    min_rno=min_rno+1;
                }
                fs.read((char*)&pri_class[std],sizeof(primary));
            }

            if(min_rno==check)
            min_rno++;
        }
    }
    fs.close();
    fo.close();


    remove(rec_file[std]);
    rename("temp.dat",rec_file[std]);
}

void header() //19
{

    std::cout<<"\n\n\n\n\n\n\n"
    <<"***************************************************************"
    <<" REPORT CARD MANAGEMENT SYSTEM "
    <<"\n************************************************************";
    password();             //To restrict access until password is given
}

void footer() //20
{

    std::cout<<"\n\n\n\nThank you for using Report Card Management System"
    <<"\n\nMade by Astrit Manikantan"
    <<"\n12 A";

}

void password() //21
{
    char check[25]={"password"},ch,cont='n';
    std::cout<<"\n\nEnter Password to Continue\n";
    while(cont=='n')
    {
        char pass[25]={'\0'};
        int i=0;
        // ch=getche();


        // while(ch!=13)
        // {
        //     std::cout<<"\b*";
        //     pass[i]=ch;
        //     i++;
        //     ch=getche();
        // }

        std::cin>>pass;
        if(!(strcmp(pass,check)))
            cont='y';
        else
        std::cout<<"\n\nWrong Password. Please try again\n";
    }
}

#endif