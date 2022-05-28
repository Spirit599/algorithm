// NP



#include<iostream>
#include<cstring>
using namespace std;

const int MAX_SIZE = 16;

int sum = 0;
int ans = 0;

void dfs_half(int arr[], int n, int index, bool vis[], int find, int cur)
{
	if(find == cur)
	{
		ans = max(ans, cur);
	}

	for(int i = index; i < n; ++i)
	{
		if(!vis[i])
		{
			cur += arr[i];
			vis[i] = true;
			dfs_half(arr, n, i + 1, vis, find, cur);
			vis[i] = false;
			cur -= arr[i];
		}
	}
}


void dfs(int arr[], int n, int index, bool vis[])
{
	if(!(sum & 1))
		dfs_half(arr, n, 0, vis, sum / 2, 0);

	//printf("sum = %d\n", sum);
	for(int i = index; i < n; ++i)
	{
		sum -= arr[i];
		vis[i] = true;
		dfs(arr, n, i + 1, vis);
		vis[i] = false;
		sum += arr[i];
	}
}


int main(int argc, char const *argv[])
{
	int T = 0;
	scanf("%d", &T);
	int n = 0;
	int arr[MAX_SIZE];
	bool vis[MAX_SIZE];

	while(T--)
	{
		scanf("%d", &n);
		sum = 0;
		ans = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		int sum_copy = sum;
		//printf("%d\n", sum_copy);
		memset(vis, 0, sizeof(vis));
		dfs(arr, n, 0, vis);

		int ret = sum_copy - 2 * ans;
		printf("%d\n", ret);

	}
	return 0;
}