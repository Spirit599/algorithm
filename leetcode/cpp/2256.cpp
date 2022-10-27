class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        int n = nums.size();
        long long pre[n + 1];
        memset(pre, 0, sizeof(pre));
        
        for(int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + nums[i];
        long long allSum = pre[n];

        int ans = n;
        int minn = INT_MAX;
        for(int i = n - 1; i >= 0; --i)
        {
            long long prev = pre[i];
            long long next = allSum - prev;
            int prevNum = i + 1;
            int nextNum = n - prevNum;
            printf("%lld %d\n", prev,prevNum);
            if(nextNum == 0)
                nextNum = 1;
            int diff = abs((prev / prevNum) - (next / nextNum));
            printf("%d\n", diff);
            if(diff <= minn)
            {
                minn = diff;
                ans = i;
            }
        }

        return ans;
    }
};