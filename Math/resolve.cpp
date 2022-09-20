#include<iostream>
using namespace std;

// 短除法
// 分解质因数
// sqrt(n)

int main(int argc, char const *argv[])
{
	int cnt = 0;
	long long n;
	cin >> n;
	for(long long i = 2; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			++cnt;
			while(n % i == 0)
			{
				n = n / i;
			}
		}
	}
	if(n != 1)
		printf("%d\n", cnt + 1);
	else
		printf("%d\n", cnt);

	return cnt;
}