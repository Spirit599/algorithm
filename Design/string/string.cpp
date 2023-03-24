#include "string.h"

using namespace jiangxy;

void test()
{
	string str("kk");
	std::cout<<str<<std::endl;
	string str1(str);
	std::cout<<str1<<std::endl;
	string str2 = str1;
	std::cout<<str2<<std::endl;
	string str3("zzzzz");
	str3 += str2;
	std::cout<<str3<<std::endl;
	string str4;
	str4 = str3;
	str4 += str2;
	std::cout<<str4<<std::endl;
}

int main(int argc, char const *argv[])
{
	
	test();
	return 0;
}