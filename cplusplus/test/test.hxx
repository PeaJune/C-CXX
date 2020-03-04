#ifndef __TEST_HXX__
#define __TEST_HXX__

#include <iostream>

class CTest0
{
    private:
        int a;
    public:
        virtual void show();
        virtual void show(int a);
};

class Ctest1 : public CTest0
{
    private:
        int b;
    public:
        virtual void show();
};

#endif