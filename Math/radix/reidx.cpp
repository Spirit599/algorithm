#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str("abcd");
	unsigned long long num = stoull(str, nullptr, 16);
	cout << num << endl;

	stringstream stream;
	stream << hex << num;
	string cur(stream.str());
	cout << cur << endl;

	return 0;
}
