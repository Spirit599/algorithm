#include<bits/stdc++.h>
using namespace std;

//二分
//求最大值
//(high - low + 1) / 2 + low
//low = mid；
//high = mid + 1；
//求最小值
//mid = (high - low) / 2 + low;
//low = mid + 1;
//high = mid;


const double eps = 1e-8;
const long long MOD = 99997867;

long long find_right_index(long long zuobiao[], long long max_right, long long n)
{

	long long high = n - 1;
	long long low = 0;
	while(low != high)
	{
		long long mid = (high - low + 1) / 2 + low;
		//cout<<low<<" "<<mid<<" "<<high<<endl;
		if(zuobiao[mid] == max_right)
		{
			return mid;
		}
		else if(zuobiao[mid] < max_right)
		{
			low = mid;
		}
		else
		{
			high = mid - 1;
		}
		//cout<<low<<" "<<mid<<" "<<high<<endl;
	}
	return low;
}

long long find_left_index(long long zuobiao[], long long max_left, long long n)
{

	long long high = n - 1;
	long long low = 0;
	while(low != high)
	{
		long long mid = (high - low) / 2 + low;
		//cout<<low<<" "<<mid<<" "<<high<<endl;
		if(zuobiao[mid] == max_left)
		{
			return mid;
		}
		else if(zuobiao[mid] > max_left)
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
		//cout<<low<<" "<<mid<<" "<<high<<endl;
	}
	return low;
}

int main(int argc, char const *argv[])
{
	long long n;
	long long distance;
	cin >> n >> distance;
	long long zuobiao[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> zuobiao[i];
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		long long one = zuobiao[i];
		long long max_right = one + distance;
		long long max_left = one - distance;

		long long right_index = find_right_index(zuobiao, max_right, n);
		long long right_num = right_index - i;

		// long long left_index = find_right_index(zuobiao, max_left, n);
		// long long left_num = i - left_index;

		

		//cout<<right_num<<endl;

		long long sum = right_num;// + left_num;
		//cout<<sum<<endl;
		ans += ((sum) % MOD * ((sum - 1) % MOD) / 2) % MOD;
	}
	cout<<ans % MOD<<endl;



	return 0;
}

