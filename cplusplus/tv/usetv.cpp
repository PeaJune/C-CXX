#include <iostream>

#include "tv.hxx"

int main()
{
    using std::cout;
    using std::endl;

    Tv s42;
    cout<<"Initial setting for 42 TV:"<<endl;
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout<<"Adjusted settting for 42 TV:"<<endl;
    s42.chanup();
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    s58.settings();

    return 0;
}