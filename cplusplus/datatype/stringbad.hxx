#ifndef __STRINGBAD_HXX__
#define __STRINGBAD_HXX__

#include <iostream>
class StringBad
{
    private:
        char *str;
        int len;
        static int num_strings;
    public:
        StringBad();
        StringBad(const char *s);
        StringBad(const StringBad &s);
        StringBad& operator=(const StringBad &s);
        ~StringBad();
        friend std::ostream & operator<<(std::ostream &os, const StringBad &st);
};

#endif