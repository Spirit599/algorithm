#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	vector<int> edges[n + 1];
	int x,y;
	for(int i = 0; i < n - 1; ++i)
	{
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int rank[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> rank[i];
	int low, high, start;
	const int mod = 1e9 + 7;


	function<long long(int, int)> dfs = [&](int fa, int cur) -> long long {

		if((rank[cur] < low) || (rank[cur] > high) || (rank[cur] == low && cur > start))
			return 0;

		long long ret = 1;
		for(int next : edges[cur])
		{
			if(next == fa)
				continue;
			ret = (ret * (1 + dfs(cur, next))) % mod;
		}

		return ret;
	};

	long long ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		low = rank[i];
		high = rank[i] + k;
		start = i;
		ans = (ans + dfs(-1, i)) % mod;
		// cout<<ans<<endl;
	}

	cout<<ans<<endl;

	return 0;
}