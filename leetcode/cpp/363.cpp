class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                matrix[i][j] += matrix[i - 1][j];
            }
        }

        vector<int> zeros(n);
        matrix.insert(matrix.begin(), zeros);
        set<int> memo;
        int ans = INT_MIN;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                memo.clear();
                memo.insert(0);
                int preSum = 0;
                for(int l = 0; l < n; ++l)
                {
                    preSum += matrix[i][l] - matrix[j][l];
                    auto it = memo.lower_bound(preSum - k);
                    if(it != memo.end())
                    {
                        ans = max(ans, preSum - *it);
                    }
                    memo.insert(preSum);
                }
            }
        }
        return ans;
    }
};