#include "vector.hxx"
#include <cmath>


using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::endl;

namespace VECTOR
{
    const double Rad_to_deg = 45/atan(1.0);
    void CVector::set_mag()
    {
        mag = sqrt(x*x+y*y);
    }

    void CVector::set_ang()
    {
        if(x==0.0 && y==0.0)
            ang = 0.0;
        else
            ang = atan2(y,x);
    }

    void CVector::set_x()
    {
        x = mag * cos(ang);
    }

    void CVector::set_y()
    {
        y = mag * sin(ang);
    }

    CVector::CVector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    CVector::CVector(double n1, double n2, Mode form)
    {
        if(form == RECT)
        {
            x=n1;
            y=n2;
            set_mag();
            set_ang();
        }else if(form = POL)
        {   
            mag = n1;
            ang = n2*Rad_to_deg;
            set_x();
            set_y();
        }else
        {
            cout<<"Incorrect 3rd argument to Vector() --";
            cout<<"Vector set to 0";
            x = y = mag = ang = 0.0;
            mode = RECT;            
        }
    }

    void CVector::reset(double n1, double n2, Mode form)
    {
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form = POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() --";
            cout << "Vector set to 0";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    CVector::~CVector()
    {

    }

    void CVector::polar_mode()
    {
        mode = POL;
    }
    
    void CVector::rect_mode()
    {
        mode = RECT;
    }
    

    CVector CVector::operator+(const CVector &b)const
    {
        return CVector(x+b.x, y+b.y);
    }

    CVector CVector::operator-(const CVector &b)const
    {
        return CVector(x-b.x, y-b.y);
    }

    CVector CVector::operator-()const
    {
        return CVector(-x, -y);
    }

    CVector CVector::operator*(double n)const
    {
        return CVector(n*x, n*y);
    }

    CVector operator*(double n, const CVector &a)
    {
        return a*n;
    }

    std::ostream& operator<<(std::ostream &os, const CVector &v)
    {
        if(v.mode == CVector::RECT)
        {
            os<<"(x,y) = ("<<v.x<<","<<v.y<<")";
        }else if(v.mode == CVector::POL)
        {
            os<<"(m, a) = ("<<v.mag<<","<<v.ang*Rad_to_deg<<")";
        }else
        {
            os<<"CVector object mode is invalid.";
        }
        return os;
    }

} // namespace VECTOR
