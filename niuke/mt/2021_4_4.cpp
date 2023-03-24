#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {

	int n,m;
	cin >> m >> n;
	vector<pii> dp(m + 1, make_pair(-1, -1));

	int cur;
	for(int i = 0; i < n; ++i)
	{
		cin >> cur;
		if(dp[cur].first == -1)
		{
			dp[cur].first = i;
			dp[cur].second = i;
		}
		else
		{
			dp[cur].first = min(dp[cur].first, i);
			dp[cur].second = max(dp[cur].second, i);
		}
	}

	
	int k = m;
	int minn = -1;
	int maxx = -1;
	vector<int> backArr;
	while(k >= 1)
	{
		if(dp[k].first == -1)
			;
		else if(minn == -1)
		{
			backArr.push_back(k);
			minn = dp[k].first;
			maxx = dp[k].second;
		}
		else
		{
			backArr.push_back(k);
			if(dp[k].second > minn)
				break;
			minn = dp[k].first;
			maxx = dp[k].second;
		}
		--k;
	}
	

	minn = -1;
	maxx = -1;
	int idx = 1;
	int backArrSize = backArr.size();
	reverse(backArr.begin(), backArr.end());
	int ans = 0;
	// cout<<"backArrSize = "<<backArrSize<<endl;
	for(int i = 1; i <= m; ++i)
	{
		if(idx != backArrSize)
			k = backArr[idx - 1];
		else
			k = backArr.back();
		// cout<<"k = "<<k<<endl;
		ans += m - k + 1;
		if(dp[i].first == -1)
		{
			continue;
		}
		else if(minn == -1)
		{
			minn = dp[i].first;
			maxx = dp[i].second;
			
		}
		else
		{
			if(maxx > dp[i].first)
				break;
			minn = dp[k].first;
			maxx = dp[k].second;
		}
		// cout<<ans<<" "<<maxx<<" "<<idx<<" "<< dp[backArr[idx]].first<<endl;
		while(idx < backArrSize && maxx > dp[backArr[idx]].first)
			++idx;

	}
		
		
	cout<<ans<<endl;
	
	return 0;
}