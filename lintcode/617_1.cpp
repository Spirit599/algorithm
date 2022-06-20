// 617 · 子数组的最大平均值 II
class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
	bool check(vector<int>& nums, int k, double ave)
	{
		int n = nums.size();
		double pre_sum[n];

		double sum = 0;
		for(int i = 0; i < n; ++i)
		{
			sum += nums[i] - ave;
			pre_sum[i] = sum;
			cout<<pre_sum[i]<<" ";
		}
		cout<<endl;

		double minn = 0;
		for(int i = k - 1; i < n; ++i)
		{
			if(pre_sum[i] - minn > 0)
				return true;
			minn = min(minn, pre_sum[i - k + 1]);
		}

		return false;


	}
    double maxAverage(vector<int> &nums, int k) {
        
        int n = nums.size();
        int maxx = -0x7fffffff;
        int minn = 0x7fffffff;
        for(int i = 0; i < n; ++i)
        {
        	maxx = max(maxx, nums[i]);
        	minn = min(minn, nums[i]);        	
        }

        double eps = 1e-5;
        double high = maxx;
        double low = minn;

        while(low + eps < high)
        {
        	double mid = (low + high) / 2;
        	cout<<low<<" "<<mid<<" "<<high<<endl;
        	if(check(nums, k, mid))
        		low = mid;
        	else
        		high = mid;
        }

        return high;
    }
};