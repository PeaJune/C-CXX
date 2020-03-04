#include <iostream>
#include <curl/curl.h>
#include <cstdio>
#include <cstring>
#include "json.hxx"


size_t recv_data(void *buffer, size_t size, size_t nmemb, void *uesrp);

using namespace std;

int flag = 0;

int main(int argc, char **argv)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;

    fp = fopen("./test.log", "w+");
    if(fp == NULL)
    {
        cout<<"open file failed!"<<endl;
        return -1;
    }

    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.84.33/cgi-bin/version.cgi");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "filename=version_192_168_83_44&data=[{name=hello,age=16},{name=world,age=20}]");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, recv_data);
    //curl_easy_setopt(curl, CURLOPT_RETURNTRANSFER, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 30000);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    curl_easy_setopt(curl, CURLOPT_HEADER, 1);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/curl_post.cookie");

    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        cout<<"error number:"<<res<<endl;
        curl_easy_cleanup(curl);
        return -1;
    }
    cout<<"send post success"<<endl;
    curl_easy_cleanup(curl);
    fclose(fp);
    if(flag == 1)
	cout<<"send POST success"<<endl;
    else
	cout<<"send POST failed"<<endl;
    return 0;
}

size_t recv_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
    char *s;
    s = (char *)buffer;
    printf("###%s\n", s);
    if(strstr(s, "version_ok") != NULL)
	flag = 1;
	
    return size*nmemb;//fwrite(buffer, size, nmemb, fp);
}
