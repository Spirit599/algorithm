class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        //int m = matrix[0].size();

        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < (n - n / 2); ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};