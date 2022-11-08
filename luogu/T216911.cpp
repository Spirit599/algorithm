// dfs序

#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int in[maxn];
int out[maxn];
int treeNum[maxn];
int depthOfIndex[maxn];
vector<int> heightNode[maxn];
vector<int> edges[maxn];

int indexxx = 0;
int dfs(int fa, int cur, int depth)
{
	depthOfIndex[cur] = depth;
	heightNode[depth].push_back(cur);
	int num = 1;
	in[cur] = indexxx++;
	for(int next : edges[cur])
	{
		if(fa != next)
			num += dfs(cur, next, depth + 1);
	}
	out[cur] = indexxx;
	return treeNum[cur] = num;
}

bool isSon(int fa, int son)
{
	return in[fa] < in[son] && in[son] <= out[fa];
}

int main(int argc, char const *argv[])
{
	memset(treeNum, 0, sizeof(treeNum));
	memset(depthOfIndex, 0, sizeof(depthOfIndex));
	int n, t;
	scanf("%d%d",&n,&t);
	for(int i = 0; i < n - 1; ++i)
	{
		int from,to;
		scanf("%d%d",&from,&to);
		edges[from].push_back(to);
		edges[to].push_back(from);
	}
	
	dfs(0, 1, 1);

	int yellowLevel = maxn - 1;
	while(t--)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op == 1)
		{
			yellowLevel = x;
		}
		else
		{
			int myLevel = depthOfIndex[x];
			if(myLevel >= yellowLevel)
			{
				printf("%d\n", treeNum[x]);
				continue;
			}
			int ans = 0;
			for(int nodeIndex : heightNode[yellowLevel])
			{
				if(isSon(x, nodeIndex))
					ans += treeNum[nodeIndex];
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}