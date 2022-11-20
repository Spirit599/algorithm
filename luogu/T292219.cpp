#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	unordered_set<string> memo;
	while(1)
	{
		string str;
		cin >> str;
		if(str == "0")
			break;
		auto it = memo.find(str);
		if(it == memo.end())
		{
			printf("%s", str.c_str());
			memo.insert(str);
		}
	}

	return 0;
}