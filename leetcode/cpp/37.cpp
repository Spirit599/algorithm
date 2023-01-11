class Solution {
public:
    
    void solveSudoku(vector<vector<char>>& board) {

        bool rows[9][10];
        bool cols[9][10];
        bool mats[3][3][10];
        bool find = false;
        vector<pair<int, int>> needFilling;

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(mats, 0, sizeof(mats));
        
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == '.')
                {
                    needFilling.emplace_back(i, j);
                }
                else
                {
                    int num = board[i][j] - '0';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    mats[i / 3][j / 3][num] = true;
                }
            }
        }

        int k = needFilling.size();

        function<void(int)> dfs = [&](int depth) {

            if(depth == k)
                find = true;
            if(find)
                return ;

            auto [x, y] = needFilling[depth];
            for(int i = 1; i <= 9 && !find; ++i)
            {
                if(!rows[x][i] && !cols[y][i] && !mats[x / 3][y / 3][i])
                {
                    rows[x][i] = true;
                    cols[y][i] = true;
                    mats[x / 3][y / 3][i] = true;
                    board[x][y] = i + '0';
                    dfs(depth + 1);
                    rows[x][i] = false;
                    cols[y][i] = false;
                    mats[x / 3][y / 3][i] = false;

                }
            }
        };

        dfs(0);
    }
};