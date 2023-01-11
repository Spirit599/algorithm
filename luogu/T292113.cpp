#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i = 0; i < n; ++i)
		scanf("%d",&a[i]);
	sort(a, a + n);
	int w;
	scanf("%d",&w);
	for(int i = n - 1; i >= 0; --i)
	{
		if(a[i] <= w)
		{
			w = a[i];
			break;
		}
	}

	int ans = 0;
	int v = 0;
	for(int i = 0; i < n; ++i)
	{
		if(v + a[i] <= w)
		{
			v += a[i];
			++ans;
		}
		else
			break;
	}
	printf("%d\n", ans);
	return 0;
}