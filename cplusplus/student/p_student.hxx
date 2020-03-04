#ifndef __P_STUDENT_HXX__
#define __P_STUDENT_HXX__

#include <iostream>
#include <valarray>
#include <cstring>

class PStudent : private std::string, private std::valarray<double>
{
    private:
        typedef std::valarray<double> ArrayDb;
        std::ostream & arr_out(std::ostream &os)const;
    public:
        PStudent() : std::string("Null Studnet"),ArrayDb(){}
        explicit PStudent(const std::string &s)
            : std::string(s),ArrayDb(){}
        explicit PStudent(int n) : std::string("Null Student"),ArrayDb(n){}
        PStudent(const std::string &s, int n)
            : std::string(s),ArrayDb(n){}
        PStudent(const std::string &s, const ArrayDb &a)
            : std::string(s), ArrayDb(a){}
        PStudent(const std::string &str, const double *pd, int n)
            : std::string(str), ArrayDb(pd, n){}
        ~PStudent(){}
        double Average()const;
        double & operator[](int i);
        double operator[](int i)const;
        const std::string & Name()const;
        //friend
        friend std::istream & operator>>(std::istream &is, PStudent &stu);
        friend std::istream & getline(std::istream &is, PStudent &stu);
        friend std::ostream & operator<<(std::ostream &os, const PStudent &stu);
};

#endif