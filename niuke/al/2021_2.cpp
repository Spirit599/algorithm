#include<bits/stdc++.h>
using namespace std;
const int MOD = (1e9+7);

int main(int argc, char const *argv[])
{
	int t;
    scanf("%d",&t);

	while(t--)
	{
		long long a,b,n;
		cin >> a >> b >> n;
		long long dp1 = a % MOD;
		long long dp2 = (a * a % MOD - 2 * b % MOD + MOD) % MOD;
		if(n == 1)
		{
			cout<<dp1<<endl;
		} 
		else if(n == 2)
		{
			cout<<dp2<<endl;
		}
		else
		{
			while(n != 2)
			{
				long long temp = dp2;
				dp2 = (temp * a % MOD - b * dp1 % MOD + MOD) % MOD;
				dp1 = temp;
				--n;
			}
			// if(dp2 < 0)
			// 	dp2 += MOD;
			cout<<dp2<<endl;
		}
	}

	return 0;
}