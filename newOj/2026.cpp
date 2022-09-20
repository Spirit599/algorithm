#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

bool check(int cap, int nums[], int arr[], int x, int n)
{
	for(int i = cap - 1; i >= 0; --i)
	{
		int get = min(x, nums[i]);
		x -= get;
		nums[i] -= get;
		arr[i] += get;
		if(x == 0)
			break;
	}
	// printf("x = %d\n", x);
	if(x > 0)
		return false;
	for(int i = 0; i < n; ++i)
	{
		if(i + cap >= n)
			continue;

		int xx = arr[i];
		for(int j = i + cap; j > i; --j)
		{
			int get = min(xx, nums[j]);
			xx -= get;
			nums[j] -= get;
			arr[j] += get;
			// printf("%d %d\n", j, arr[j]);
			if(xx == 0)
				break;
		}
		if(xx > 0)
			return false;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	int n, x;
	scanf("%d%d", &n,&x);
	x = 2 * x;
	int nums[n];
	int arr[n];
	int vol[n];
	for(int i = 0; i < n - 1; ++i)
		scanf("%d", &nums[i]);

	int low = 1;
	int high = n;
	while(low != high)
	{
		int mid = (low + high) >> 1;
		memset(arr, 0, sizeof(arr));
		memcpy(vol, nums, sizeof(vol));
		// printf("%d\n", mid);
		if(check(mid, vol, arr, x, n - 1))
			high = mid;
		else
			low = mid + 1;
	}

	printf("%d\n", low);
	return low;
}