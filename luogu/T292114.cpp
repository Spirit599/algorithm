#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n,k,x,y;
	scanf("%d%d%d%d",&n,&k,&x,&y);
	string steps;
	cin >> steps;
	int ans[n][n];
	int conSecond[n][n];
	memset(ans, 0, sizeof(ans));
	memset(conSecond, 0, sizeof(conSecond));

	for(char c : steps)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				++conSecond[i][j];
			}
		}
		// printf("%d %d\n", x,y);
		conSecond[y - 1][x - 1] = 0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				ans[i][j] += conSecond[i][j];
			}
		}
		if(c == 'N')
			++y;
		else if(c == 'S')
			--y;
		else if(c == 'W')
			--x;
		else
			++x;
	}

	for(int j = 0; j < n; ++j)
	{
		for(int i = 0; i < n; ++i)
		{
			printf("%d ", ans[n - j - 1][i]);
		}
		printf("\n");
	}

	return 0;
}