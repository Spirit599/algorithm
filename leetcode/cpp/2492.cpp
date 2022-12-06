class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
		

		vector<pair<int, int>> edges[n + 1];
		for(auto& road : roads)
		{
			edges[road[0]].emplace_back(road[1], road[2]);
			edges[road[1]].emplace_back(road[0], road[2]);
		}

		bool vis[n + 1];
		memset(vis, 0, sizeof(vis));
		vector<int> canGet;

		function<void(int)> dfs = [&](int cur) {

			if(vis[cur])
				return ;
			vis[cur] = true;
			canGet.emplace_back(cur);

			for(auto& next : edges[cur])
				dfs(next.first);
		};

		dfs(1);

		int minn = INT_MAX;
		for(int next : canGet)
		{
			// printf("%d\n", next);
			for(auto& edge : edges[next])
			{
				minn = min(minn, edge.second);
			}
		}

		return minn;

    }
};