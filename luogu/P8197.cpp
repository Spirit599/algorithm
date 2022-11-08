#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int T;
	scanf("%d",&T);
	unordered_map<int, int> memo;
	while(T--)
	{
		memo.clear();
		int n;
		scanf("%d",&n);
		int a[n];
		for(int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
			++memo[a[i]];
		}
		int b[n];
		for(int i = 0; i < n; ++i)
		{
			scanf("%d",&b[i]);
			--memo[b[i]];
		}
		bool yes = true;
		for(auto& kv : memo)
		{
			if(kv.second != 0)
			{
				yes = false;
				break;
			}
		}
		if(!yes)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i = 0; i < n; ++i)
		{
			if(a[i] == b[i])
				continue;
			int j = i + 1;
			for(; j < n; ++j)
			{
				if(b[i] == a[j])
					break;
			}
			for(int k = j; k >= i + 1; --k)
			{
				swap(a[k], a[k - 1]);
				printf("%d %d\n", k + 1, k);
			}
		}
		printf("0 0\n");

	}

	return 0;
}