class Solution {
public:
    int arrayNesting(vector<int>& nums) {

        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == -1)
                continue;
            int depth = 0;
            int cur = i;
            while(1)
            {
                ++depth;
                int t = cur;
                cur = nums[cur];
                nums[t] = -1;
                if(cur == i)
                    break;
            }
            ans = max(ans, depth);

        }

        return ans;
    }
};