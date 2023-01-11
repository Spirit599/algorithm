class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int m = board.size();
        int n = board[0].size();
        board[m - 1][n - 1] = '0';

        int maxScore[m][n];
        int maxCnt[m][n];
        memset(maxCnt, -1, sizeof(maxCnt));
        memset(maxScore, -1, sizeof(maxScore));
        maxScore[0][0] = 0;
        maxCnt[0][0] = 1;
        int MOD = 1e9 + 7;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'X' || (i == 0 && j == 0))
                    continue;

                int ms1 = -1;
                int ms2 = -1;
                int ms3 = -1;
                int mc1 = -1;
                int mc2 = -1;
                int mc3 = -1;
                if(i)
                {
                    ms1 = maxScore[i - 1][j];
                    mc1 = maxCnt[i - 1][j];
                }
                if(j)
                {
                    ms2 = maxScore[i][j - 1];
                    mc2 = maxCnt[i][j - 1];
                }
                if(i && j)
                {
                    ms3 = maxScore[i - 1][j - 1];
                    mc3 = maxCnt[i - 1][j - 1];
                }
                if(ms1 != -1 || ms2 != -1)
                {
                    if(ms1 > ms2)
                    {
                        maxScore[i][j] = ms1 + board[i][j] - '0';
                        maxCnt[i][j] = mc1;
                    }
                    else if(ms1 < ms2)
                    {
                        maxScore[i][j] = ms2 + board[i][j] - '0';
                        maxCnt[i][j] = mc2;
                    }
                    else
                    {
                        maxScore[i][j] = ms2 + board[i][j] - '0';
                        maxCnt[i][j] = (mc2 + mc1) % MOD;
                    }
                }
                else if(ms3 != -1)
                {
                    // printf("%d %d\n", i, j);
                    maxScore[i][j] = ms3 + board[i][j] - '0';
                    maxCnt[i][j] = mc3;
                }
            }
        }

        if(maxScore[m - 1][n - 1] != -1)
            return {maxScore[m - 1][n - 1], maxCnt[m - 1][n - 1]};
        else
            return {0, 0};
    }
};