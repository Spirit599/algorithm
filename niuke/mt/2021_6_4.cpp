#include <bits/stdc++.h>
using namespace std;


const int maxn = 102;
const int maxTarget = 25 * maxn;
long long dp[maxn + 1][maxTarget + 1];
long long mod = 998244353;

void init_dp()
{
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for(int i = 1; i <= maxn; ++i)
	{
		for(int j = 0; j <= maxTarget; ++j)
		{
			for(int k = 0; k < 26; ++k)
			{
				if(j - k >= 0)
				{
					dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
					
				}
			}
		}
		// for(int j = 0; j <= maxTarget; ++j)
		// {
		// 	printf("%d %d %d\n",i,j,dp[i][j]);
		// }
	}
}

int main(int argc, char const *argv[])
{
	init_dp();

	int n;
	string str;
	while(cin >> n)
	{
		cin >> str;
		int sum = 0;
		for(char c : str)
			sum += c - 'A';

		cout<<dp[n][sum]<<endl;
	}

	return 0;
}