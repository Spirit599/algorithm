#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m, a, b;
	while(scanf("%d %d %d %d",&n, &m, &b, &a) != EOF)
	{
		int cakes[m];
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", &cakes[i]);
		}
		int minn = 1001;
		int maxx = 0;
		for (int i = 0; i < m; ++i)
		{
			minn = min(minn, cakes[i]);
			maxx = max(maxx, cakes[i]);
		}
		int aa = min(a, b);
		int bb = max(a, b);
		if(minn == aa && maxx == bb)
		{
			printf("YES\n");
			continue;
		}
		else if(minn != aa && maxx == bb)
		{
			if(minn > aa && n - m >= 1)
			{
				printf("YES\n");
				continue;
			}
			else
			{
				printf("NO\n");
				continue;
			}
		}
		else if(minn == aa && maxx != bb)
		{
			if(maxx < bb && n - m >= 1)
			{
				printf("YES\n");
				continue;
			}
			else
			{
				printf("NO\n");
				continue;
			}
		}
		else
		{
			if(maxx < bb && minn > aa && n - m >= 2)
			{
				printf("YES\n");
				continue;
			}
			else
			{
				printf("NO\n");
				continue;
			}
		}
	}
	return 0;
}