// 最大子矩阵

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int tmp[n];
        int maxx = matrix[0][0];

        int r1 = 0;
        int r2 = 0;
        int c1 = 0;
        int c2 = 0;

        for(int j = 0; j < n; ++j)
        {
            int presum = 0;
            for(int i = 0; i < m; ++i)
            {
                presum += matrix[i][j];
                matrix[i][j] = presum;
            }
        }

        for(int up = -1; up < m; ++up)
        {
            for(int down = up + 1; down < m; ++down)
            {
                if(up != -1)
                {
                    for(int j = 0; j < n; ++j)
                        tmp[j] = matrix[down][j] - matrix[up][j];
                }
                else
                {
                    for(int j = 0; j < n; ++j)
                        tmp[j] = matrix[down][j];
                }
                int left = -1;
                int cur = 0;
                for(int j = 0; j < n; ++j)
                {
                    if(cur > 0)
                        cur += tmp[j];
                    else
                    {
                        left = j;
                        cur = tmp[j];
                    }

                    if(cur > maxx)
                    {
                        maxx = cur;
                        r1 = up + 1;
                        r2 = down;
                        c1 = left;
                        c2 = j;

                    }
                }
            }
        }

        return vector<int>({r1, c1, r2, c2});

    }
};