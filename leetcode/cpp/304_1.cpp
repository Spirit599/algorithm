// 304. 二维区域和检索 - 矩阵不可变

class NumMatrix {
public:
    vector<vector<int>> *psum;
    int m;
    int n;
    NumMatrix(vector<vector<int>>& matrix) {

        psum = &matrix;
        m = matrix.size();
        n = matrix[0].size();
        for(int i = 0; i < m; ++i)
        {
            int pre = 0;
            for(int j = 0; j < n; ++j)
            {
                pre += matrix[i][j];
                matrix[i][j] = pre;
                if(i != 0)
                    matrix[i][j] += matrix[i - 1][j];
                // printf("%d ", matrix[i][j]);
            }
            // printf("\n");
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        vector<vector<int>>& sum = *psum;

        int all = sum[row2][col2];
        int sub1 = col1 - 1 >= 0 ? sum[row2][col1 - 1] : 0;
        int sub2 = row1 - 1 >= 0 ? sum[row1 - 1][col2] : 0;
        int add = row1 - 1 >= 0 && col1 - 1 >= 0 ? sum[row1 - 1][col1 - 1] : 0;

        //printf("%d %d %d %d\n", all, sub1, sub2, add);

        return all - sub1 - sub2 + add;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */