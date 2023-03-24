#include<bits/stdc++.h>
using namespace std;


typedef pair<int, int> pii;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	unordered_map<int, int> dp[n + 1];

	vector<int> edges[n + 1];
	int x,y;
	for(int i = 0; i < n - 1; ++i)
	{
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	int colors[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> colors[i];


	function<void(int, int)> dfs = [&](int fa, int cur) -> void {

		dp[cur][colors[cur]] += 1;
		for(int next : edges[cur])
		{
			if(next == fa)
				continue;
			dfs(cur, next);
			for(auto& kv : dp[next])
				dp[cur][kv.first] += kv.second;
		}
	};


	dfs(-1, 1);

	vector<pii> ans[n + 1];
	for(int i = 1; i <= n; ++i)
	{
		for(auto& [k, v] : dp[i])
		{
			ans[i].emplace_back(v, -k);
		}
		sort(ans[i].begin(), ans[i].end(), greater<>());
	}


	int querySize;
	cin >> querySize;
	int query;
	while(querySize--)
	{
		cin >> query;
		cout<<-ans[query][0].second<<endl;

	}

	return 0;
}

