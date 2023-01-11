class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        
        int n = matrix[0].size();
        vector<int> zeros(n);
        matrix.insert(matrix.begin(), zeros);

        int m = matrix.size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i > 0)
                    matrix[i][j] += matrix[i - 1][j];
                if(j > 0)
                    matrix[i][j] += matrix[i][j - 1];
                if(i > 0 && j > 0)
                    matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }

        unordered_map<int, int> memo;
        int ans = 0;

        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                memo.clear();
                memo[0] = 1;
                for(int k = 0; k < n; ++k)
                {
                    int cur = matrix[i][k] - matrix[j][k];
                    int key = cur - target;
                    auto it = memo.find(key);
                    if(it != memo.end())
                        ans += it->second;
                    ++memo[cur];
                }
            }
        }

        return ans;
    }
};