// 单调栈

class Solution {
public:
    int longestWPI(vector<int>& hours) {

        int n = hours.size();
        int ans = 0;
        int preSum[n + 1];
        preSum[0] = 0;
        vector<int> stk({0});

        for(int i = 0; i < n; ++i)
        {
            preSum[i + 1] = preSum[i] + (hours[i] > 8 ? 1 : -1);
            if(preSum[i + 1] < preSum[stk.back()])
                stk.push_back(i + 1);
        }

        for(int i = n - 1; i >= 0; --i)
        {
            while(!stk.empty() && preSum[i + 1] > preSum[stk.back()])
            {
                ans = max(ans, i + 1 - stk.back());
                stk.pop_back();
            }
        }

        return ans;
    }
};