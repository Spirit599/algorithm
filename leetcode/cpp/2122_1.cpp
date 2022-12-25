class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        bool vis[n];
        for(int i = 1; i < n; ++i)
        {
            if(((nums[i] - nums[0]) & 1) || nums[i] == nums[0])
                continue;

            memset(vis, 0, sizeof(vis));
            int dif = nums[i] - nums[0];
            int m = 1;
            vis[0] = true;
            vis[i] = true;
            int left = 1;
            int right = i + 1;
            vector<int> ret({nums[0] + (dif >> 1)});
            while(right < n)
            {
                while(vis[left])
                    ++left;

                vis[left] = true;
                while(right < n && nums[left] + dif != nums[right])
                    ++right;
                if(right != n)
                {
                    ret.emplace_back(nums[left] + (dif >> 1));
                    vis[right] = true;
                    ++m;
                }
                ++right;
            }

            if(m == n >> 1)
            {
                printf("%d\n", dif);
                return ret;
            }
        }


        vector<int> ans;
        return ans;
    }
};