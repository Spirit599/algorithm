//498. 对角线遍历


class Solution {
public:
    enum d
    {
        UP = 0,
        DOWN = 1
    };
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int y = mat.size();
        int x = mat[0].size();
        vector<int> ans;
        int dire = UP;
        int i = 0; 
        int j = 0;

        while(1)
        {
            ans.push_back(mat[i][j]);
            if(i == y - 1 && j == x - 1)
                break;

            if(dire == UP)
            {
                if(i - 1 >= 0 && j + 1 < x)
                {
                    --i;++j;
                }
                else if(j == x - 1)
                {
                    ++i;
                    dire = DOWN;
                }
                else
                {
                    ++j;
                    dire = DOWN;
                }
            }
            else if(dire = DOWN)
            {
                if(i + 1 < y && j - 1 >= 0)
                {
                    ++i;--j;
                }
                else if(i == y - 1)
                {
                    ++j;
                    dire = UP;
                }
                else
                {
                    ++i;
                    dire = UP;
                }
            }
        }

        return ans;
    }
};