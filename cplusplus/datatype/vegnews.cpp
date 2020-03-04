#include <iostream>

#include "stringbad.hxx"

using std::cout;

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
    using std::endl;
    {
        cout<<"Staring an inner block.\n";
        StringBad headline1("Celery stalks at Midnight.");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");

        cout<<"headline1: "<<headline1<<endl;
        cout<<"headline2: "<<headline2<<endl;
        callme1(headline1);
        cout<<"headline1: "<<headline1<<endl;
        callme2(headline2);
        cout<<"headline2: "<<headline2<<endl;
        cout<<"Initialize one object to another:\n";
        StringBad sailor = sports;
        cout<<"sailor: "<<sailor<<endl;
        cout<<"Assign one object to another:\n";

        StringBad knot;

        knot = headline1;
        cout<<"knot: " <<knot<<endl;
        cout<<"Exiting the block.\n";
    }
    cout<<"End of main()\n";

    return 0;
}

void callme1(StringBad &rsb)
{
    cout<<"StringBad passed by referece: \n";
    cout<<"     \""<<rsb<<"\""<<std::endl;
}

void callme2(StringBad sb)
{
    cout<<"String passed by value: \n";
    cout<<"     \""<<sb<<"\"\n";
}
