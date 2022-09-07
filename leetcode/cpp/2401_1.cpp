// 2401. 最长优雅子数组

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int ans = 0;
        int left = -1;
        int right = -1;
        int cur = 0;
        int n = nums.size();

        while(right + 1 < n)
        {
        	if((cur & nums[right + 1]) == 0)
        	{
        		cur |= nums[right + 1];
        		++right;
        		ans = max(ans, right - left);
        	}
        	else
        	{
        		++left;
        		cur ^= nums[left];	
        	}
        	cout<<cur<<endl;
        }

        return ans;
    }
};