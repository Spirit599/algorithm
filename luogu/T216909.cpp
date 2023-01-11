#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int maxx = 2000005;
	bool vis[maxx];
	memset(vis, 0, sizeof(vis));
	bool isPrime[maxx];
	memset(isPrime, 0, sizeof(isPrime));
	for(int i = 2; i < maxx; ++i)
	{
		if(!vis[i])
			isPrime[i] = true;
		for(int j = i; j < maxx; j += i)
			vis[j] = true;
	}

	int sum[maxx];
	memset(sum, 0, sizeof(sum));
	for(int i = 2; i < maxx; ++i)
	{
		if(isPrime[i])
			sum[i] = sum[i - 1] + 1;
		else
			sum[i] = sum[i - 1];
	}
	
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int q;
		scanf("%d",&q);
		int bit = 0;
		int ans = 0;
		while(q)
		{
			if(q & 1)
			{
				int right = (1 << (bit + 1)) - 1;
				int left = 1 << bit;
				ans += sum[right] - sum[left - 1];
			}
			++bit;
			q = q >> 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}