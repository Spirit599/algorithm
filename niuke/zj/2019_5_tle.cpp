#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const double eps = 1e-8;

//邻接矩阵
//最小距离
//TSP

int ans = 0x3f3f3f3f;

void dfs(vector<vector<int>>& lingjie, int index, int depth, bool visit[], int cost, int n)
{
	if(cost > ans)
		return ;
	if(depth == n)
	{
		ans = min(ans, cost + lingjie[index][0]);
	}
	//cout<<index<<" "<<cost<<endl;

	for (int j = 0; j < n; ++j)
	{
		if(lingjie[index][j] != 0 && !visit[j])
		{
			visit[j] = true;
			dfs(lingjie, j, depth + 1, visit, cost + lingjie[index][j], n);
			visit[j] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<vector<int>> lingjie(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int k;
			cin >> k;
			lingjie[i].push_back(k);
		}
	}

	bool visit[n];
	memset(visit,0,sizeof(visit));
	visit[0] = true;

	dfs(lingjie, 0, 1, visit, 0, n);

	cout<<ans<<endl;
	return 0;
}

