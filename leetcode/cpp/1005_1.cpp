class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while(k--)
        {
            int cur = pq.top();
            pq.pop();
            pq.push(-cur);
        }

        // int ans = accumulate(pq.begin(), pq.end(), 0);

        int ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};