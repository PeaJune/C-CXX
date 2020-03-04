#include <iostream>
#include "mytime0.hxx"

/*=,(),[],->,为只能通过成员函数重载*/

int main(void)
{
    using std::cout;
    using std::endl;

    CTime planning;
    CTime coding(2, 40);
    CTime fixing(5, 55);
    CTime total;
    CTime diff;
    CTime adjusted;
    CTime add_hours;

    cout<<"planning time = ";
    planning.Show();

    cout<<"coding time = ";
    coding.Show();

    cout<<"fixing time = ";
    fixing.Show();
    cout<<endl;

    total = coding+fixing;
    cout<< "coding + fixing = ";
    total.Show();
    cout<<endl;

    CTime morefixing(3,28);
    cout<<"more fixing time = ";
    morefixing.Show();
    cout<<endl;

    total = morefixing.operator+(total);
    cout<<"morefixing.perator+(total) = ";
    total.Show();
    cout<<endl;

    diff = coding - fixing;
    cout<<"coding - fixing = ";
    diff.Show();
    cout<<endl;

    adjusted = total * 1.5;
    cout<<"adjuested work time =";
    adjusted.Show();
    cout<<endl;

    add_hours = total+10;
    cout<<"total.hours + 10 = ";
    add_hours.Show();
    cout<<endl;

    CTime c_res;

    c_res = 10*total;
    cout<<"10 * total = ";
    c_res.Show();
    cout<<endl;

    cout<<c_res<<endl;


    return 0;
}