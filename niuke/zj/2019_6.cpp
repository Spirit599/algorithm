#include<bits/stdc++.h>
using namespace std;

//硬币
//贪心

typedef long long ll;
const double eps = 1e-8;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	n = 1024 - n;
	int ans = 0;
	while(n >= 64)
	{
		n = n - 64;
		++ans;
	}
	while(n >= 16)
	{
		n = n - 16;
		++ans;
	}
	while(n >= 4)
	{
		n = n - 4;
		++ans;
	}
	while(n >= 1)
	{
		n = n - 1;
		++ans;
	}
	cout<<ans<<endl;
	return 0;
}

