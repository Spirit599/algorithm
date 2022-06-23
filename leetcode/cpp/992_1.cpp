// 992. K 个不同整数的子数组

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

    	//return subarraysNoMoreThanK(nums, k) - subarraysNoMoreThanK(nums, k - 1);
    	return subarraysNoLessThanK(nums, k) - subarraysNoLessThanK(nums, k + 1);
    }
    int subarraysNoMoreThanK(vector<int>& nums, int k)
    {
    	int n = nums.size();
    	// if(n == 0)
    	// 	return 0;

    	int ans = 0;
    	int left = -1;
    	int right = -1;
    	unordered_map<int, int> memo;

		while(right < n)
		{
			if(memo.size() <= k)
			{
				ans += right - left;
				++right;
				if(right < n)
					++memo[nums[right]];
			}
			else
			{
				
				++left;
				if(--memo[nums[left]] == 0)
					memo.erase(nums[left]);
			}
		}

    	return ans;
    }
    int subarraysNoLessThanK(vector<int>& nums, int k) //大于等于
    {
    	int n = nums.size();
    	int ans = 0;
    	int right = -1;
    	int left = -1;
    	unordered_map<int, int> memo;

    	while(right < n)
    	{
    		if(memo.size() < k)
    		{
    			++right;
    			if(right < n)
    				++memo[nums[right]];
    		}
    		else
    		{
    			ans += n - right;
    			++left;
    			if(--memo[nums[left]] == 0)
    				memo.erase(nums[left]);
    		}
    	}

    	return ans;
    }
};