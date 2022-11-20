#include<bits/stdc++.h>
using namespace std;

// 并查集


int findFa(int fa[], int cur)
{
	while(fa[cur] != -1)
	{
		cur = fa[cur];
	}
	return cur;
}

int main(int argc, char const *argv[])
{
	
	int n, m;
	scanf("%d%d",&n,&m);
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		scanf("%d",&a[i]);

	pair<int, int> edges[n + 1];
	for(int i = 1; i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edges[i] = make_pair(x, y);
	}
	bool isInvaild[n + 1];
	memset(isInvaild, 0, sizeof(isInvaild));

	int op[m];
	int arg1[m];
	int arg2[m];
	for(int i = 0; i < m; ++i)
	{
		int o;
		scanf("%d",&o);
		op[i] = o;
		if(o == 1)
		{
			int ar1;
			scanf("%d",&ar1);
			arg1[i] = ar1;
			if(ar1 == n)
				continue;
			isInvaild[ar1] = true;
		}
		else if(o == 2)
		{
			int ar1,ar2;
			scanf("%d%d",&ar1,&ar2);
			arg1[i] = ar1;
			int dif = ar2 - a[ar1];
			a[ar1] = ar2;
			arg2[i] = dif;
		}
		else if(o == 3)
		{
			int ar1;
			scanf("%d",&ar1);
			arg1[i] = ar1;
		}
	}



	int faSum[n + 1];
	memcpy(faSum, a, sizeof(faSum));
	// for(int i = 1; i <= n; ++i)
	// 	printf("%d ", faSum[i]);
	// printf("kk\n");
	int fa[n + 1];
	int height[n + 1];
	memset(height, 0, sizeof(height));
	memset(fa, -1, sizeof(fa));
	for(int i = 1; i < n; ++i)
	{
		if(isInvaild[i])
			continue;
		int f1 = findFa(fa, edges[i].first);
		int f2 = findFa(fa, edges[i].second);
		if(height[f1] < height[f2])
		{
			fa[f1] = f2;
			faSum[f2] += faSum[f1];
		}
		else if(height[f1] > height[f2])
		{
			fa[f2] = f1;
			faSum[f1] += faSum[f2];
		}
		else
		{
			fa[f2] = f1;
			faSum[f1] += faSum[f2];
			++height[f1];
		}
	}

	vector<int> ans;
	for(int i = m - 1; i >= 0; --i)
	{
		if(op[i] == 1)
		{
			if(arg1[i] == n)
				continue;
			int f1 = findFa(fa, edges[arg1[i]].first);
			int f2 = findFa(fa, edges[arg1[i]].second);
			if(height[f1] < height[f2])
			{
				fa[f1] = f2;
				faSum[f2] += faSum[f1];
			}
			else if(height[f1] > height[f2])
			{
				fa[f2] = f1;
				faSum[f1] += faSum[f2];
			}
			else
			{
				fa[f2] = f1;
				faSum[f1] += faSum[f2];
				++height[f1];
			}
		}
		else if(op[i] == 2)
		{
			int f1 = findFa(fa, arg1[i]);
			faSum[f1] -= arg2[i];
		}
		else
		{
			int f1 = findFa(fa, arg1[i]);
			ans.push_back(faSum[f1]);
		}
	}

	reverse(ans.begin(), ans.end());
	for(int num : ans)
		printf("%d\n", num);

	return 0;
}