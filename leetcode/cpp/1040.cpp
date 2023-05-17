class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {

        sort(stones.begin(), stones.end());
        int n = stones.size();
        int e1 = stones[n - 1] - stones[1] - n + 2;
        int e2 = stones[n - 2] - stones[0] - n + 2;
        int maxn = max(e2, e1);
        if(e1 == 0 || e2 == 0)
            return {min(maxn, 2), maxn};

        int cnt = 0;
        int left = 0;
        for(int right = 0; right < n; ++right)
        {
            while(stones[right] - stones[left] + 1 > n)
                ++left;
            cnt = max(cnt, right - left + 1);
        }
        return {n - cnt, maxn};
    }
};