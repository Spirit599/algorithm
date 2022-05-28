//字符串
//重复串查找
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	int n = str.size();

	for (int len = n / 2; len >= 1; --len)
	{
		int cnt = 0;
		for (int j = 0; j + len < n; ++j)
		{
			int k = j + len;
			if(str[j] == str[k])
				++cnt;
			else
				cnt = 0;
			if(cnt == len)
			{
				cout<<2 * cnt<<endl;
				return 0;
			}
		}
	}
	cout<<0<<endl;
	return 0;
}