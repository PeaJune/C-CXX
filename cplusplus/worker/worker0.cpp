#include "worker0.hxx"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker()
{

}

void Worker::Set()
{
    cout<<"Enter worker's name: ";
    getline(cin, fullname);
    cout<<"Enter worker's ID: ";
    cin >> id;
    while(cin.get() != '\n')
        continue;
}

void Worker::Show()const
{
    cout<<"Name: "<<fullname<<std::endl;
    cout<<"Employee ID: "<<id<<std::endl;
}

//waiter methods
void Waiter::Set()
{
    Worker::Set();
    cout<<"Enter waiter's panache rating: ";
    cin >> panache;
    while(cin.get() != '\n')
        continue;
}

void Waiter::Show()
{
    cout<<"Category: waiter\n";
    Worker::Show();
    cout<<"panache rating: "<<panache<<std::endl;
}

//Singer methods
char *Singer::pv[] = {"other", "alto", "contralto",
                    "soprano", "bass", "baritone", "tenor"};
void Singer::Set()
{
    Worker::Set();
    cout<<"Enter number for singer's vocal range: \n";
    int i;
    for(i=0; i<Vtypes; i++)
    {
        cout<<i<<":"<<pv[i]<<"    ";
        if(i%4 == 3)
            cout<<std::endl;
    }
    if(i%4 !=0)
        cout<<endl;
    while(cin>>voice && (voice < 0 || voice >= Vtypes))
        cout<<"Please enter a value: value >0 and < "<<Vtypes <<endl;
    
    while(cin.get() != '\n')
        continue;
}

void Singer::Show()const
{
    cout<<"Category: singer\n";
    Worker::Show();
    cout<<"Vocal range: " << pv[voice]<<std::endl;
}
