#include <iostream>
#include "test.hxx"


int main(void)
{
    CTest0 t1;
    Ctest1 t2;

    CTest0 *p;

    t1.show();
    t1.show(1);
    t2.show();

    p = &t1;
    p->show();
    p->show(1);

    p = &t2;
    p->show();

    return 0;
}