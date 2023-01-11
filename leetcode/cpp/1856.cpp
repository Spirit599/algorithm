// 单调栈

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {

        int n = nums.size();
        int left[n];
        memset(left, -1, sizeof(left));
        int right[n];
        for(int i = 0; i < n; ++i)
            right[i] = n;

        stack<int> sta;
        long long pre[n + 1];
        pre[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            while(!sta.empty() && nums[sta.top()] >= nums[i])
            {
                right[sta.top()] = i;
                sta.pop();
            }
            if(!sta.empty())
                left[i] = sta.top();
            sta.push(i);

            pre[i + 1] = pre[i] + nums[i];
        }



        // for(int i = 0; i < n; ++i)
        //     printf("%d ", left[i]);
        // printf("\n");
        // for(int i = 0; i < n; ++i)
        //     printf("%d ", right[i]);
        // printf("\n");
        long long ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int l = left[i] + 1;
            int r = right[i] - 1;
            long long cur = nums[i] * (pre[r + 1] - pre[l]);
            ans = max(ans, cur);
        }


        return ans % (1000000007);
    }
};