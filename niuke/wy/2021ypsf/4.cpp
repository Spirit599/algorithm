#include<iostream>
using namespace std;

const int MAX_SIZE = 1000005;

int main(int argc, char const *argv[])
{
	int n;
	int arr[MAX_SIZE];
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	long long ans = 0;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] == 1)
			continue;
		else if(arr[i] == 2 || arr[i] == 3)
			ans += 1;
		else if(arr[i] & 1)
			ans += ((arr[i] - 3) / 2 + 1);
		else
			ans += (arr[i] / 2);
	}

	printf("%lld\n", ans);

	return 0;
}
