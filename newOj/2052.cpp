#include<iostream>
#include<cstring>
using namespace std;

// 动态规划
const long long MOD = 998244353;

int main(int argc, char const *argv[])
{
	
	long long dp = 0;
	long long sum = 1;
	long long factorial = 1;
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i)
	{
		long long n_dp = (i * dp + sum * factorial) % MOD;
		long long n_sum = (sum + i) % MOD;
		long long n_factorial = (factorial * i) % MOD;
		dp = n_dp;
		sum = n_sum;
		factorial = n_factorial;

	}

	printf("%lld\n", dp);

	return 0;
}