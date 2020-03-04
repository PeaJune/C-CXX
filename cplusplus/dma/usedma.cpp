#include <iostream>

#include "dma.hxx"

int main(void)
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Meractor", "Buffalo object", 5);

    cout<<"Displaying baseDMA object:\n";
    cout<<shirt<<endl;

    cout<<"Displaying lacksDMA object: \n";
    cout<<balloon<<endl;

    cout<<"Displaying hasDMA object: \n";
    cout<<map<<endl;

    lacksDMA balloon2(balloon);
    cout<<"Result of lacksDMA copy:\n";
    cout<<balloon2<<endl;

    hasDMA map2;
    map2 = map;
    cout<<"Result of hasDMA assigment: \n";
    cout<<map2<<endl;

    return 0;
}