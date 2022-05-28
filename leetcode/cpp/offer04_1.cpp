class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();

        int i = m - 1;
        int j = 0;

        while(i >= 0 && j < n)
        {
            //cout<<matrix[i][j]<<endl;
            if(matrix[i][j] > target)
                --i;
            else if(matrix[i][j] < target)
                ++j;
            else
                return true;
        }
        return false;
    }
};