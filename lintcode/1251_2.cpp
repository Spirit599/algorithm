// 1251 · 拆分子数组

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param m: an integer
     * @return: return a integer
     */
    int splitArray(vector<int> &nums, int m) {
        
        long long high = 0;
        int low = 0;
        for(int num : nums)
        {
        	high += num;
        	low = max(low, num);
        }

        while(low != high)
        {
        	long long mid = (high - low) / 2 + low;
        	if(check(nums, m, mid))
        		high = mid;
        	else
        		low = mid + 1;
        }

        return low;
    }

    bool check(vector<int>& nums, int m, long long mid)
    {
    	int cnt = 1;
    	long long sum = 0;

    	for(int num : nums)
    	{
    		sum += num;
    		if(sum > mid)
    		{
    			++cnt;
    			if(cnt > m)
    				return false;
    			sum = num;
    		}
    	}

    	return true;
    }
};