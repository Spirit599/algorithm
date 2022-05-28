#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

//64位
const long long MAX_LONGLONG = 0x7fffffffffffffff;
//32位
const int MAX_INT = 0x7fffffff;

int max_dis = 0;
int ans = 0x3f3f3f3f;

vector<int> dfs(int cur, vector<int> edges[], int score[], int k, bool visit[])
{
	int maxx = score[cur];
	int minn = score[cur];
	int nums = 1;
	
	
	for (auto p : edges[cur])
	{
		if(!visit[p])
		{
			visit[p] = true;
			vector<int> tmp = dfs(p, edges, score, k, visit);	

			if(tmp[2] <= k)
			{
				if(tmp[0] - tmp[1] > max_dis)
				{
					ans = p;
					max_dis = tmp[0] - tmp[1];	

				}
				else if(tmp[0] - tmp[1] == max_dis)
				{
					if(p < ans)
						ans = p;
				}
			}
			maxx = max(maxx, tmp[0]);
			minn = min(minn, tmp[1]);
			nums = nums + tmp[2];
		}

	}

	//cout<<cur<<" "<<maxx<<" "<<minn<<" "<<nums<<endl;

	return {maxx, minn, nums};
}

int main(int argc, char const *argv[])
{
	
	int n, k;
	cin >> n >> k;

	int score[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> score[i];

	vector<int> edges[n + 1];
	for (int i = 1; i <= n - 1; ++i)
	{
		int p1 = 0;
		int p2 = 0;
		cin >> p1 >> p2;
		edges[p1].push_back(p2);
		edges[p2].push_back(p1);
	}

	int root = 0;
	cin >> root;

	bool visit[n + 1];
	memset(visit, 0, sizeof(visit));

	visit[root] = true;
	dfs(root, edges, score, k, visit);

	cout<<ans<<endl;
	return 0;
}

