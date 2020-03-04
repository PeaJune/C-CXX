#include "workermi.hxx"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker()
{}

void Worker::Data()const
{
    cout<<"Name: "<<fullname<<endl;
    cout<<"Employee ID: "<<id<<endl;
}

void Worker::Get()
{
    getline(cin, fullname);
    cout<<"Enter Wokrer's ID: ";
    cin>>id;
    while(cin.get() != '\n')
        continue;
}

void Waiter::Set()
{
    cout<<"Enter waiter's name: ";
    Worker::Data();
    Get();
}

void Waiter::Show()const
{
    cout<<"GateGory: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data()const
{
    cout<<"panache rating : "<<panache<<endl;
}

void Waiter::Get()
{
    cout<<"Enter waiter's panache rating: ";
    cin>>panache;
    while(cin.get() != '\n')
        continue;
}

char *Singer::pv[Singer::Vtypes] = 
{
    "other", "alto", "contralto",
    "soprano", "bass", "baritone",
    "tenor"
};
