#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

//64位
const long long MAX_LONGLONG = 0x7fffffffffffffff;
//32位
const int MAX_INT = 0x7fffffff;



int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	string str_n, str_m;
	cin >> str_n >> str_m;

	long long ans = 0;
	int i = 0;
	int j = 0;
	while(i < n && j < m)
	{
		if(str_n[i] == str_m[j])
		{
			ans = ans + i + 1;
			++i;
			++j;
		}
		else
		{
			++i;
		}
	}
	if(j == m)
	{
		cout<<"Yes"<<endl;
		cout<<ans<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}

