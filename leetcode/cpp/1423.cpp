class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int preSum[n + 1];
        preSum[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            preSum[i + 1] = preSum[i] + cardPoints[i];
        }
        int sum = preSum[n];
        int minn = INT_MAX;
        k = n - k;
        for(int i = k; i <= n; ++i)
        {
            minn = min(minn, preSum[i] - preSum[i - k]);
        }
        return sum - minn;
    }
};