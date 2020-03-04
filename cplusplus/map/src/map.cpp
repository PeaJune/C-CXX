#include <iostream>
#include <vector>
#include <map>
#include "config.h"

using namespace std;

template<class T, class T1>
void Read(T &a, T1 &b);

template <>
void Read<const string, map<string, string>>(const std::string &key, map<string, string> &n_m);

map<string, string> obj;

int main() 
{
    map<string, string>::iterator obj_iter;
    map<string, string> n_obj;
    const string str("version_num");
    obj.insert(pair<string, string>("k3s-agent_version_num", "v0,0.7"));
    obj.insert(pair<string, string>("autoupdate_version_num", "v0.1.0"));
    obj.insert(pair<string, string>("download_url", "http://127.2.2.2."));
    obj.insert(pair<string, string>("first_download", "localhost"));
    
    Read(str, n_obj);

    Read("abc", "ccc");

    cout<<"res:.........................."<<endl;
    for(obj_iter=n_obj.begin(); obj_iter!=n_obj.end(); obj_iter++)
    {
        cout<<obj_iter->first<<":"<<obj_iter->second<<endl;
    }

    string ip("192.168.84.44");
    string::iterator str_iter;
    cout<<"-----------"<<endl;
    for(str_iter=ip.begin(); str_iter != ip.end(); str_iter++)
    {
        cout<<*str_iter;
        cout<<"====";
        if(*str_iter == '.')
            *str_iter = '_';
    }
    cout<<endl;
    

    cout<<ip.c_str()<<endl;

    return 0;
}

template <>
void Read<const string, map<string, string>>(const std::string &in_key, map<string, string> &n_m)
{   
    
    map<string, string>::iterator obj_iter;
    string first;
    
    for (obj_iter = obj.begin(); obj_iter != obj.end(); obj_iter++)
    {
        cout << obj_iter->first << ":" << obj_iter->second << endl;
        first = obj_iter->first;

        
        if (first.find(in_key) != string::npos)
        {
            cout << "find the version:" << first << endl;
            n_m.insert(*obj_iter);
            //n_m.insert(pair<string, string>(obj_iter->first, obj_iter->second));
        }
    }
}

template<class T, class T1>
void Read(T &a, T1 &b)
{
    cout<<"aaaaaaaaaaa"<<endl;
    return;
}
