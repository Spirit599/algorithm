#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const double eps = 1e-8;

//邻接矩阵
//最小距离
//状态压缩DP
//TSP



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int lingjie[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> lingjie[i][j];
		}
	}

	int S_size = 1 << n;
	//cout<<S_size<<endl;
	int dp[n][S_size];
	memset(dp, 0x3f, sizeof(dp));

	dp[0][1] = 0; //从第1个节点开始

	for (int S = 1; S < S_size; ++S) // 从第1个节点开始
	{
		for (int i = 0; i < n; ++i)
		{
			if(S & (1 << i)) //访问过 i 节点 
			{
				for (int j = 0; j < n; ++j)
				{
					if(!(S & (1 << j))) // 没访问过 j 节点
					{
						//结果 | 上去,也就是 + 
						dp[j][S | (1 << j)] = min(dp[j][S | (1 << j)], dp[i][S] + lingjie[i][j]);
					}
				}
			}
		}
	}

	int ans = 0x7fffffff;
	for (int i = 1; i < n; ++i)
	{
		ans = min(ans, dp[i][S_size - 1] + lingjie[i][0]);
	}
	cout<<ans<<endl;

	
	return 0;
}

