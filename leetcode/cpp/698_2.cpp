// 698. 划分为k个相等的子集
//状态压缩

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int allSum = accumulate(nums.begin(), nums.end(), 0);
        if(allSum % k)
            return false;
        int part = allSum / k;
        sort(nums.begin(), nums.end(), greater<int>());

        int n = nums.size();
        bool vis[1 << n];
        memset(vis, 0, sizeof(vis));

        function<bool(int ,int)> dfs = [&](int state, int curSum) -> bool {

            if(state == 0)
                return true;
            if(vis[state])
                return false;

            vis[state] = true;

            for(int i = 0; i < n; ++i)
            {
                if(curSum + nums[i] > part)
                    continue;

                if(((state >> i) & 1))
                {
                    if(dfs(state ^ (1 << i), (curSum + nums[i]) % part))
                        return true;
                }
            }

            return false;

        };

        return dfs((1 << n) - 1, 0);
    }
};