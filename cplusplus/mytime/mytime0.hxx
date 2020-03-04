#ifndef __MYTIME0_HXX__
#define __MYTIME0_HXX__
#include <iostream>
#include <ostream>

class CTime{
    private:
        int hours;
        int minutes;
    public:
        CTime();
        CTime(int h, int m=0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h=0, int m=0);
        CTime Sum(const CTime &t)const;
        void Show()const;
        CTime operator+(const CTime &t)const;
        CTime operator-(const CTime &t)const;
        CTime operator*(double mult)const;
        CTime operator+(const int h)const;
        friend CTime operator*(double m, const CTime &t);
        friend std::ostream& operator<<(std::ostream &os, const CTime &t);
};

#endif