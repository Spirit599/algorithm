#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

//64位
const long long MAX_LONGLONG = 0x7fffffffffffffff;
//32位
const int MAX_INT = 0x7fffffff;

int main(int argc, char const *argv[])
{
	int n, m, k;
	cin >> n >> m >> k;

	int value[n];
	for (int i = 0; i < n; ++i)
		cin >> value[i];

	int i = 0;
	int ans = 0;
	while(i + m - 1 < n)
	{
		bool ok = true;
		//cout<<"------------"<<endl;
		for (int j = i; j <= i + m - 1; ++j)
		{
			//cout<<j<<" ";
			if(value[j] < k)
			{
				ok = false;
				break;
			}
		}
		//cout<<endl;
		if(ok)
			++ans;

		++i;
	}
	cout<<ans<<endl;
	return 0;
}

