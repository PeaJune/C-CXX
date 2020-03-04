#include <iostream>
#include <cstring>

#include <p_student.hxx>

using std::ostream;
using std::istream;
using std::endl;
using std::string;

double PStudent::Average()const
{
    if(ArrayDb::size() > 0)
        return ArrayDb::sum()/ArrayDb::size();
    else
    {
        return 0;
    }
}

const string &PStudent::Name()const
{
    return (const string &)*this;
}

double & PStudent::operator[](int i)
{
    return ArrayDb::operator[](i);
}

double PStudent::operator[](int i)const
{
    return ArrayDb::operator[](i);
}

//private method

ostream & PStudent::arr_out(ostream &os)const
{
    int i;
    int lim = ArrayDb::size();
    
    if(lim > 0)
    {
        for(i=0; i<lim; i++)
        {
            os<<ArrayDb::operator[](i)<< " ";
            if(i%5 == 4)
                os<<endl;
        }
        if(i%5 == 0)
            os<<endl;
    }
    else
    {
        os<<" Empty array";
    }
    return os;
}

//friend

istream & operator>>(istream &is , PStudent &stu)
{
    is>>(string &)stu;
}

ostream & operator<<(ostream &os, const PStudent &stu)
{
    os<<" Scores for "<<(const string&)stu;
    stu.arr_out(os);

    return os;
}