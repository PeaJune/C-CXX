#include <iostream>
#include "json.hxx"

using namespace std;
using namespace nlohmann;
int main(int argc, char **argv)
{
	json object_value = {{"age": 21}};


	cout<<object_value.dump(0)<<endl;


	return 0;
}
