//滑动窗口 nlogn

class Solution {
public:
    int findLHS(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        // if(nums[0] == nums[n - 1])
        //     return 0;

        int end = 0;
        int start = 0;
        int ans = 0;
        while(end < n)
        {
            //cout<<end<<endl;
            while(end < n && nums[end] == nums[start])
                ++end;
            while(end + 1 < n && nums[end] == nums[end + 1])
                ++end;
            while(end < n && nums[end] - nums[start] > 1)
                ++start;
            if(end < n && nums[end] - nums[start] == 1)
                ans = max(ans, end - start + 1);
            ++end;
        }


        return ans;
    }
};