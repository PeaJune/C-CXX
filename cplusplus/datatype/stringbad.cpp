#include <cstring>

#include "stringbad.hxx"

using std::cout;

int  StringBad::num_strings = 0;

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout<<num_strings<<": \""<<"\" default object created\n";
}

StringBad::StringBad(const char *s)
{
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_strings++;
    cout<<num_strings<<": \""<<str<<"\" object created\n";
}

StringBad::StringBad(const StringBad &s)
{
    num_strings++;
    len = s.len;
    str=new char(len+1);
    std::strcpy(str, s.str);
    cout<<num_strings<< ":"<<str<<"\" #######object created\n";
}

StringBad& StringBad::operator=(const StringBad &st)
{
    cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaa"<<std::endl;
    if(this == &st)
    {
        return *this;
    }
    cout<<"l...."<<str<<std::endl;
    cout<<"bbbbbbbbb"<<std::endl;
    delete []str;
    cout<<"ccccc"<<std::endl;
    len = st.len;
    str=new char[len+1];
    std:strcpy(str, st.str);

    return *this;
}

StringBad::~StringBad()
{
    cout<<"\""<<str<<"\" object deleted, ";
    --num_strings;
    cout<<num_strings<<" left\n";
    delete []str;
}

std::ostream& operator<<(std::ostream &os, const StringBad &st)
{
    os<<st.str;
    return os;
}
