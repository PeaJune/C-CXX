#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "vector.hxx"

int main(void)
{
    using namespace std;
    using namespace VECTOR;

    srand(time(0));
    double direction;
    CVector step;
    CVector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    ofstream fout;
    fout.open("thewalk.txt");

    cout<<"Enter target distance(1 ot quit): ";
    while(cin>>target)
    {
        cout<<"Enter step length: ";
        if(!(cin>>dstep))
            break;
        while(result.magval()<target)
        {
            direction = rand()%360;
            step.reset(dstep, direction, CVector::POL);
            result = result + step;
            steps++;
        }
        cout<<"After " <<steps <<" steps, the subject "
            "has the following location:"<<endl;
        result.polar_mode();
        cout << result << endl;
        fout<<result<<endl;
        cout<<"or\n"<<result<<endl;
        cout<<"Average outward distance per step = "
            <<result.magval()/steps<<endl;
        steps = 0;
        result.reset(0.0,0.0);
        cout<<"Enter target distance (q to quit): ";
    }

    cout<<"Bye!"<<endl;
    cin.clear();

    while(cin.get()!='\n')
        continue;

    return 0;

}