#include <iostream>
#include "test.hxx"


void CTest0::show()
{
    std::cout<<"this is base class."<<std::endl;
}

void CTest0::show(int a)
{
    std::cout<<"this is base class, have param."<<a<<std::endl;
}

void Ctest1::show()
{
    std::cout<<"this is child class."<<std::endl;
}