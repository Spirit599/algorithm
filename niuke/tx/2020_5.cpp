#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// 贪心
// 区间
// 最少区间覆盖
// 排序

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if(p1.first != p2.first)
		return p1.first < p2.first;
	else
		return p1.second > p2.second;
}

int main(int argc, char const *argv[])
{
	int n, l;
	cin >> n >> l;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i].first >> vec[i].second;
	}

	sort(vec.begin(), vec.end(), cmp);

	int start = 0;
	int end = 0;
	int ans = 0;
	int i = 0;
	int j = 0;

	while(end < l && i != n)
	{	
		for (j = i; j < n; ++j)
		{
			/* code */
			if(vec[j].first <= start)
			{
				if(vec[j].second > end)
				{
					end = vec[j].second;
				}
			}
			else
			{
				break;
			}
		}
		start = end;
		i = j;
		++ans;
	}

	if(end >= l)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

