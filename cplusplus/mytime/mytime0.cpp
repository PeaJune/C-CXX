#include <iostream>
#include "mytime0.hxx"

CTime::CTime()
{
    hours = minutes = 0;
}

CTime::CTime(int h, int m)
{
    hours = h;
    minutes = m;
}

void CTime::AddMin(int m)
{
    minutes += m;
    hours += minutes/60;
    minutes%=60;
}

void CTime::AddHr(int h)
{
    hours += h;
}

void CTime::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

CTime CTime::Sum(const CTime &t)const
{
    CTime sum;
    sum.minutes = minutes+t.minutes;
    sum.hours = hours+t.hours + sum.minutes/60;
    sum.minutes %= 60;

    return sum;
}

void CTime::Show()const
{
    std::cout<<hours<<" hours,"<<minutes<<" minutes"<<std::endl;
}

CTime CTime::operator+(const CTime &t)const
{
    CTime sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes/60;
    sum.minutes = sum.minutes%60;

    return sum;
}

CTime CTime::operator-(const CTime &t)const
{
    CTime diff;
    int tot1, tot2;

    tot1 = t.minutes+60*t.hours;
    tot2 = minutes + 60*hours;

    diff. minutes = (tot2-tot1)%60;
    diff.hours = (tot2-tot1)/60;

    return diff;
}

CTime CTime::operator*(double mult)const
{
    CTime result;
    long totalminutes = hours * mult * 60 + minutes;

    result.hours = totalminutes/60;
    result.minutes = totalminutes%60;

    return result;
}

CTime CTime::operator+(const int h)const
{
    CTime sum_add;

    sum_add.hours = hours + h;
    sum_add.minutes = minutes;

    return sum_add;
}

CTime operator*(double m, const CTime &t)
{
    CTime aj;
    long total = t.minutes + t.hours * 60;
    total *= m;

    aj.hours = total / 60;
    aj.minutes = total % 60;

    return aj;
}

std::ostream& operator<<(std::ostream &os, const CTime &t)
{
    os<<t.hours <<" hours "<<t.minutes<<" minutes";
}