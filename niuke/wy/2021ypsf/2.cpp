#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	long long e = 0;
	long long em = 0;
	long long m = 0;
	long long mh = 0;
	long long h = 0;

	scanf("%lld %lld %lld %lld %lld",
		&e, &em, &m, &mh, &h);

	long long e_num = e + em;
	long long m_num = em + m + mh;
	long long h_num = mh + h;
	long long sum = e + em + m + mh + h;

	long long ans = min(e_num, m_num);
	ans = min(ans, h_num);
	ans = min(ans, sum / 3);

	printf("%lld\n", ans);
	return 0;
}