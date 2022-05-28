class Solution {
private:
    bool ans = false;
    int word_size = 0;
    int n = 0;
    int m = 0;
public:
    void dfs(vector<vector<char>>& board, string word, int index, int cur_i, int cur_j, bool visit[200][200])
    {
        if(ans)
            return ;
        if(index == word_size)
        {
            ans = true;
            return ;
        }
        int dires[] = {1, 0, -1, 0, 1};
        for (int k = 0; k < 4; ++k)
        {
            int i = cur_i + dires[k];
            int j = cur_j + dires[k + 1];
            if(i >= 0 && i < n && j >=0 && j < m && !visit[i][j] && board[i][j] == word[index])
            {
                visit[i][j] = true;
                dfs(board, word, index + 1, i, j, visit);
                visit[i][j] = false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {

        word_size = word.size();
        n = board.size();
        m = board[0].size();
        bool visit[200][200];
        memset(visit, 0, sizeof(visit));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(board[i][j] == word[0])
                {
                    visit[i][j] = true;
                    dfs(board, word, 1, i, j, visit);
                    if(ans)
                        return true;
                    visit[i][j] = false;
                }
            }
        }

        return ans;
    }
};