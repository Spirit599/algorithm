class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        

        int n = nums.size();
        long long preMin[n];
        long long ans = LONG_MAX;
        memset(preMin, 0, sizeof(preMin));
        int k = n / 3;

        long long preSum = 0;
        priority_queue<int> pq1;
        for(int i = 0; i < k; ++i)
        {
            preSum += nums[i];
            pq1.emplace(nums[i]);
        }
        preMin[k - 1] = preSum;

        for(int i = k; i <= 2 * k - 1; ++i)
        {
            pq1.emplace(nums[i]);
            preMin[i] = preMin[i - 1] - (pq1.top() - nums[i]);
            pq1.pop();
        }


        long long sufSum = 0;
        priority_queue<int, vector<int>, greater<int>> pq2;
        long long sufMax[n];
        memset(sufMax, 0, sizeof(sufMax));
        for(int i = 3 * k - 1; i > 2 * k - 1; --i)
        {
            sufSum += nums[i];
            pq2.emplace(nums[i]);
        }
        sufMax[2 * k] = sufSum;

        for(int i = 2 * k - 1; i >= k; --i)
        {
            pq2.emplace(nums[i]);
            sufMax[i] = sufMax[i + 1] + (nums[i] - pq2.top());
            pq2.pop();
        }

        for(int i = k; i <= 2 * k; ++i)
        {
            ans = min(ans, preMin[i - 1] - sufMax[i]);
        }

        return ans;
    }
};