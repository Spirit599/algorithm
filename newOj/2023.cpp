#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int nums[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &nums[i]);

	long long ans = 0;
	long long pre[n];
	long long sum = 0;
	for(int i = n - 1; i >= 0; --i)
	{
		sum += nums[i];
		pre[i] = sum;
	}

	for(int i = 0; i < n - 1; ++i)
	{
		//cout<<nums[i]<<" "<<pre[i + 1]<<endl;
		ans += nums[i] * pre[i + 1];
	}
	cout<<ans<<endl;
	return ans;
}