#include <iostream>
#include <string>

#include "static.hxx"

using namespace std;

int CStatic::pa = 0;
int CStatic::pb = 0;

void CStatic::show()
{
    std::cout<<"pa:"<<pa<<endl;
    std::cout<<"pb:"<<pb<<endl;
}

int main(int argc, char **argv)
{
    CStatic a;
    CStatic::pa = 100;
    //CStatic::pb = 200;
    cout<<"Helo"<<endl;
    CStatic::set_pb(999);
    CStatic::pa=444;

    CStatic::show();

    return 0;
}