#include<bits/stdc++.h>
using namespace std;
#define MAX_SCORE (1001)

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> nums(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += max(nums[i] - (i + 1), (i + 1) - nums[i]);
	}

	cout<<ans;

	return 0;
}