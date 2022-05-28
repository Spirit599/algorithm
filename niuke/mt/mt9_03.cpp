#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int nums[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&nums[i]);
		}
		int all_sum = 0;
		int maxx = 0;
		int minn = 0;
		int m_maxx = 0;
		int m_minn = 0;
		for (int i = 0; i < n; ++i)
		{
			if(maxx + nums[i] > 0)
			{
				maxx += nums[i];
			}
			else
			{
				maxx = 0;
			}
			if(minn + nums[i] < 0)
			{
				minn += nums[i];
			}
			else
			{
				minn = 0;
			}
			all_sum += nums[i];
			m_maxx = max(m_maxx, maxx);
			m_minn = min(m_minn, minn);
		}
		printf("%d\n",max(m_maxx, all_sum - m_minn));

	}
	return 0;
}