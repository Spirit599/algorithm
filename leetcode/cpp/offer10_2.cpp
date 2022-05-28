const int MOD = 1000000007;
class Solution {
public:
	vector<vector<long long>> matrix_multiply(vector<vector<long long>>& matrix1, 
											vector<vector<long long>>& matrix2)
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
				//cout<<ans[i][j]<<endl;
			}
		}
	
		return ans;
	}
	
	vector<vector<long long>> matrix_quick_pow(vector<vector<long long>> matrix1, int n)
	{
		int m = matrix1.size();
		//cout<<n<<endl;
		vector<vector<long long>> ans(m, vector<long long>(m));
		for (int i = 0; i < m; ++i)
			ans[i][i] = 1;
	
		while(n)
		{
			//cout<<n<<endl;
			if(n & 1)
				ans = matrix_multiply(ans, matrix1);
			n = n >> 1;
			matrix1 = matrix_multiply(matrix1, matrix1);
		}
		return ans;
	}

    int fib(int n) {
    	if(n < 2)
    		return n;

    	vector<vector<long long>> x = {{1, 1}, {1, 0}};
    	x = matrix_quick_pow(x, n - 1);
    	return x[0][0];
    }
};