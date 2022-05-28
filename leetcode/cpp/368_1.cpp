//动态规划

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        if(n == 1)
            return nums;

        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = -1; //cur_index前一个可以除尽的下标
        dp[0][1] = 1; //以nums[cur_index]为最大值的子集的元素个数

        int maxx = 0;
        int index = 0;

        for (int i = 1; i < n; ++i)
        {
            bool no_son = true;
            for (int j = 0; j < i; ++j)
            {
                if(nums[i] % nums[j] == 0 && dp[i][1] < dp[j][1] + 1)
                {
                    dp[i][0] = j;
                    dp[i][1] = dp[j][1] + 1;
                    no_son = false;
                }
            }
            if(no_son)
            {
                dp[i][0] = -1;
                dp[i][1] = 1;
            }
            if(dp[i][1] > maxx)
            {
                maxx = dp[i][1];
                index = i;
            }
            //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<index<<endl;
        }

        vector<int> ans;
        if(index != -1)
            ans.push_back(nums[index]);
        int cur = dp[index][0];
        while(cur != -1)
        {
            ans.push_back(nums[cur]);
            cur = dp[cur][0];
        }

        //reverse(ans.begin(), ans.end());
        //ans.push_back(nums[index]);

        return ans;
    }
};