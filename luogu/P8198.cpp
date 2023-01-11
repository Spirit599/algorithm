#include<bits/stdc++.h>
using namespace std;


bool check(long long a[], long long capa, int k, int n)
{
	int cnt = 1;
	long long curCapa = capa;
	for(int i = 0; i < n; ++i)
	{
		if(curCapa >= a[i])
		{
			curCapa -= a[i];
		}
		else
		{
			curCapa = capa - a[i];
			++cnt;
		}
		if(cnt > k)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	long long a[n];
	long long high = 0;
	long long low = 0;
	int tmp;
	for(int i = 0; i < n; ++i)
	{

		scanf("%d",&tmp);
		a[i] = 1ll * tmp * tmp;
		high += a[i];
		low = max(low, a[i]);
	}


	while(high != low)
	{
		long long mid = (high - low) / 2 + low;
		if(check(a, mid, k, n))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}

	
	printf("%lld\n", low);

	return 0;
}