#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string str;
	while(n--)
	{
		cin >> str;
		// bool fisrtIsAlpha = false;
		bool hasElse = false;
		bool hasNum = false;
		if(!isalpha(str[0]))
		{
			cout<<"Wrong"<<endl;
			continue;
		}
		for(char c : str)
		{
			if(!isalpha(c) && !isdigit(c))
			{
				hasElse = true;
				break;
			}
			if(isdigit(c))
				hasNum = true;
		}
		if(!hasElse && hasNum)
			cout<<"Accept"<<endl;
		else
			cout<<"Wrong"<<endl;
	}
	return 0;
}