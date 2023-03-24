#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int nums[n];
	int preSum[n + 1];
	preSum[0] = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> nums[i];
		preSum[i + 1] = preSum[i] + nums[i];
		// cout<<preSum[i + 1]<<endl;
	}


	set<pii> memo;
	multiset<int, greater<int>>  valSet;
	valSet.insert(preSum[n]);
	memo.emplace(n - 1, 0);

	int rmIdx;
	for(int i = 0; i < n; ++i)
	{
		cin >> rmIdx;
		--rmIdx;
		auto it = memo.lower_bound(make_pair(rmIdx, -1));
		assert(it != memo.end());
		int ll = it->second;
		int rr = it->first;
		int val = preSum[rr + 1] - preSum[ll];
		// printf("query %d %d %d\n", ll,rr,val);
		auto itVal = valSet.find(val);
		assert(itVal != valSet.end());
		valSet.erase(itVal);
		memo.erase(it);
		int leftVal = preSum[rmIdx] - preSum[ll];
		int rightVal = preSum[rr + 1] - preSum[rmIdx + 1];
		// printf("right %d %d\n",rmIdx + 1,rr+ 1);
		if(leftVal != 0)
		{
			valSet.insert(leftVal);
			memo.emplace(rmIdx - 1, ll);
			// printf("insert %d %d %d\n", ll,rmIdx - 1,leftVal);
		}
		if(rightVal != 0)
		{
			valSet.insert(rightVal);
			memo.emplace(rr, rmIdx + 1);
			// printf("insert %d %d %d\n", rmIdx + 1, rr,rightVal);
		}

		cout<<*valSet.begin()<<endl;
	}

	return 0;
}