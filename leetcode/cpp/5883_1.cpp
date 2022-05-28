class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        int k = word.size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n - k + 1; ++j)
            {
                if(board[i][j] == '#')
                    continue;

                int start = j;
                bool ok1 = true;
                bool ok2 = true;
                for ( ;j < n && board[i][j] != '#'; ++j)
                {
                    if(board[i][j] != ' ' && j - start < k && board[i][j] != word[j - start])
                    {
                        ok1 = false;
                    }
                    if(board[i][j] != ' ' && j - start < k && board[i][j] != word[k + start - 1 - j])
                    {
                        ok2 = false;
                    }
                }
                if(j - start == k && (ok1 || ok2))
                {
                    return true;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m - k + 1; ++j)
            {
                if(board[j][i] == '#')
                    continue;

                int start = j;
                bool ok1 = true;
                bool ok2 = true;
                for ( ;j < m && board[j][i] != '#'; ++j)
                {
                    if(board[j][i] != ' ' && j - start < k && board[j][i] != word[j - start])
                    {
                        ok1 = false;
                    }
                    if(board[j][i] != ' ' && j - start < k && board[j][i] != word[k + start - 1 - j])
                    {
                        ok2 = false;
                    }
                }
                if(j - start == k && (ok1 || ok2))
                {
                    return true;
                }
            }
        }

        return false;
    }
};