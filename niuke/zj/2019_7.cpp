#include<bits/stdc++.h>
using namespace std;

  //二分 求最小值
//check
//mid = (high - low) / 2 + low;
//low = mid + 1;
//high = mid;
//check提前返回true 否则溢出longlong

typedef long long ll;
const double eps = 1e-8;

bool check(long long enemgy, long long height[], int n, int high)
{
	for (int i = 0; i < n; ++i)
	{
		if(enemgy > height[i])
		{
			enemgy += enemgy - height[i];
		}
		else
		{
			enemgy += enemgy - height[i];
		}
		//cout<<"enemgy:"<<enemgy<<endl;
		if(enemgy < 0)
			return false;
		if(enemgy > high)
			return true;
	}
	return true;
}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	long long height[n];
	long long high = 0;
	long long low = 0;

	for (int i = 0; i < n; ++i)
	{
		cin>>height[i];
		high = max(high, height[i]);
		low = min(low, height[i]);
	}

	long long maxx = high;

	while(high != low)
	{
		long long mid = (high - low) / 2 + low;
		//cout<<"mid:"<<mid<<endl;
		if(check(mid, height, n, maxx))
			high = mid;
		else
			low = mid + 1;
	}

	cout<<low<<endl;
	return 0;
}

