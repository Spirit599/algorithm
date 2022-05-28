#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n ,x;
	scanf("%d%d",&n, &x);

	vector<int> score(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&score[i]);
	}

	sort(score.begin(), score.end(), greater<int>());

	if(score[x - 1] == 0)
	{
		while(x - 1 >= 0 && score[x - 1] == 0)
		{
			--x;
		}
		printf("%d", x);
	}
	else
	{
		while(x < n && score[x - 1] == score[x])
		{
			++x;
		}
		printf("%d", x);
	}
	return 0;
}