//*******************************************************
// HEADER FILES
//*******************************************************
#include "funcdefs.h"


//******************************************************
// MAIN FUNCTION
//*******************************************************

int main()
{

    using namespace std;
    header();

    do
    {
        int choice;

        cout<<" ***** MAIN MENU *****"
        <<"\n\n1 Enter Records"
        <<"\n2 Modify Records"
        <<"\n3 Delete Records"
        <<"\n4 View"
        <<"\n5 Exit\n\n";

        cin>>choice;
        switch(choice)
        {
            case 1:enter();
            break;

            case 2:modify_record();
            break;

            case 3:del_menu();
            break;

            case 4:view_menu();
            break;

            case 5:fs.close();

            footer();

            return 1;
            default:cout<<"Sorry! Wrong Input";
        }
    }while(1);
}