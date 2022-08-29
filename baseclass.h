#ifndef baseclass
#define baseclass

#include<iostream>
#include<string>

class classes                             // Abstract base class
{
    protected:
    char name[25],failed;
    int rollno,total;
    double per;
    void highest();
    
    public:
    int getrno()
    {
        return rollno;
    }
    
    int gettotal()
    {
        return total;
    }
    
    void givename()
    {
        std::cout<<name;
    }
};

#endif