// 2333. 最小差值平方和

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
	
		int n = nums1.size();
		vector<int> diff(n);

		for(int i = 0; i < n; ++i)
		{
			diff[i] = nums1[i] - nums2[i];
			if(diff[i] < 0)
				diff[i] = -diff[i];
		}

		

		sort(diff.begin(), diff.end(), greater<int>());

		for(int i = 0; i < n; ++i)
		{
			//printf("%d ", diff[i]);
		}
		int k = k1 + k2;

		int cnt = 1;
		for(int i = 0; i + 1 < n; ++i)
		{
			int cur = diff[i];
			int next = diff[i + 1];
			long long dif = (cur - next) * cnt;
			//printf("dif = %d\n", dif);
			if(dif < k)
			{
				k -= dif;
			}
			else
			{
				int quotient = k / cnt;
				int remainder = k % cnt;
				//printf("%d %d %d\n", quotient, remainder, i);
				for(int j = 0; j < remainder; ++j)
					diff[j] = diff[i] - quotient - 1;
				for(int j = remainder; j <= i; ++j)
					diff[j] = diff[i] - quotient;
				k = 0;
				break;
			}

			++cnt;
		}

		if(k > 0)
		{
			int last = diff[n - 1];
			int quotient = k / n;
			int remainder = k % n;
			//printf("%d %d %d\n", quotient, remainder, n - 1);
			for(int j = 0; j < remainder; ++j)
				diff[j] = diff[n - 1] - quotient - 1;
			for(int j = remainder; j <= n - 1; ++j)
				diff[j] = diff[n - 1] - quotient;
			k -= n * last;
		}

		if(k > 0)
			return 0; 

		long long ans = 0;
		for(int i = 0; i < n; ++i)
		{
			//printf("%d ", diff[i]);
			ans += 1ll * diff[i] * diff[i];
		}

		return ans;
    }
};