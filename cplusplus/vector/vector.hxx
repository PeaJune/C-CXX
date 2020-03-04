#ifndef __VECTOR_HXX__
#define __VECTOR_HXX__
#include <iostream>
namespace VECTOR{

    class CVector{
    public:
        enum Mode{RECT, POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        CVector();
        CVector(double n1, double n2, Mode form=RECT);
        void reset(double n1, double n2, Mode form = RECT);

        ~CVector();
        double xval()const{return x;}
        double yval()const{return y;}
        double magval()const{return mag;}
        double angval()const{return ang;}
        void polar_mode();
        void rect_mode();
        CVector operator+(const CVector &b)const;
        CVector operator-(const CVector &b)const;
        CVector operator-()const;
        CVector operator*(double n)const;
        friend CVector operator*(double n, const CVector &a);
        friend std::ostream &operator<<(std::ostream &os, const CVector &v);
    };
}
#endif