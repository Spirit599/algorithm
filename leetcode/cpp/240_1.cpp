//贪心
//从左下角(右上角)查找

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        
        int i = n - 1;
        int j = 0;
        while(i >= 0 && j < m)
        {
            int cur_value = matrix[i][j];
            if(cur_value == target)
                return true;
            else if(cur_value > target)
                --i;
            else if(cur_value < target)
                ++j;
        }
        return false;
    }
};