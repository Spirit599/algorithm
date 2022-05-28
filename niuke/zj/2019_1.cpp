#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const double eps = 1e-8;

//字符串
//erase(i ,k) 清除 第i个位置 长度为k
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		int i = 0;
		while(i < str.size())
		{
			int str_len = str.size();
			if(i + 1 >= 0 && i + 2 >= 0 && str[i] == str[i + 1] && str[i] == str[i + 2])
			{
				str.erase(i,1);
				continue;
			}
			if(i + 1 >= 0 && i >= 0 && str[i + 1] == str[i] &&
				 i + 3 < str_len && i + 2 < str_len && str[i + 2] == str[i + 3])
			{
				str.erase(i + 2,1);
				continue;
			}
			++i;
		}
		cout<<str<<endl;
	}

	/* code */
	return 0;
}

