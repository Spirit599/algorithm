const int MOD = 1000000007;

class Solution {
public:

    vector<vector<long long>> matrix_mutli(vector<vector<long long>>& matrix1, vector<vector<long long>>& matrix2)
    {
        int n = matrix1.size();
        vector<vector<long long>> ans(n, vector<long long>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    ans[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                ans[i][j] = ans[i][j] % MOD;
            }
        }

        return ans;
    }

    vector<vector<long long>> quick_pow(vector<vector<long long>>& matrix, int n)
    {
        vector<vector<long long>> ans = {{1, 0}, {0, 1}};
        while(n)
        {
            //cout<<n<<endl;
            if(n & 1)
                ans = matrix_mutli(ans, matrix);
            n = n >> 1;
            matrix = matrix_mutli(matrix, matrix);
        }
        return ans;
    }
    int numWays(int n) {

        if(n < 2)
            return 1;

        vector<vector<long long>> x = {{1, 1}, {1, 0}};
        x = quick_pow(x, n);
        return x[0][0];
    }
};