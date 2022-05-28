#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 状态转移
// dp 动态规划
// 有限状态
// 办公 健身

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int company[n];
	int gym[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> company[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> gym[i];
	}
	int dp[3][n + 1];//0休息,1工作,2锻炼
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[2][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		if(gym[i - 1] == 1)
			dp[2][i] = min(dp[1][i - 1], dp[0][i - 1]);

		if(company[i - 1] == 1)
			dp[1][i] = min(dp[2][i - 1], dp[0][i - 1]);

		dp[0][i] = min(dp[0][i - 1], min(dp[2][i - 1], dp[1][i - 1])) + 1;

	}

	int ans = min(dp[0][n], min(dp[2][n], dp[1][n]));




	cout<<ans<<endl;

	return 0;
}

