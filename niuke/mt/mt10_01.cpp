#include<bits/stdc++.h>
using namespace std;
#define MAX_SCORE (1001)

int main(int argc, char const *argv[])
{
	int n, x, y;
	scanf("%d%d%d",&n,&x,&y);
	vector<int> score(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&score[i]);
	}
	//sort(score.begin(), score.end());

	int ans;
	int kk[MAX_SCORE];
	memset(kk,0,sizeof(kk));
	for (int i = 0; i < n; ++i)
	{
		kk[score[i]]++;
	}

	// for (int i = 2; i < MAX_SCORE; ++i)
	// {
	// 	kk[i] += kk[i - 1];
	// }

	int yes = n;
	int no = 0;
	for (int i = 1; i < MAX_SCORE; ++i)
	{
		yes = yes - kk[i];
		no = no + kk[i];
		//printf("%d %d %d\n",i,yes,no);
		if(yes >= x && yes <= y && no >= x && no <= y )
		{
			printf("%d",i);
			break;
		}
	}

	return 0;
}