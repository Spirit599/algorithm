#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	int ans = 0x3f3f3f3f;
	int minn = a[0];
	int maxx = a[n - 1];
	for(int mid = minn; mid <= maxx; ++mid)
	{
		int cur = mid - n / 2;
		int cnt = 0;
		// cout<<cur<<endl;
		for(int i = 0; i < n; ++i)
		{
			cnt += abs(cur - a[i]);
			++cur;
		}
		ans = min(ans, cnt);
	}

	cout<<ans<<endl;

	return 0;
}