// 123 · 单词搜索

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    int m = 0;
    int n = 0;
    int visit[105][105];
    bool exist(vector<vector<char>> &board, string &word) {

        if(word == "")
            return true;
        
        memset(visit, 0, sizeof(visit));
        m = board.size();
        n = board[0].size();
        int arrive = word.size();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(word[0] == board[i][j])
                {
                    visit[i][j] = 1;
                    bool ok = dfs(board, i, j, 1, arrive, word);
                    visit[i][j] = 0;
                    if(ok)
                        return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>> &board, int cur_i, int cur_j, int depth, int arrive, string& word)
    {
        if(depth == arrive)
            return true;

        int dires[] = {-1 ,0, 1, 0, -1};
        for (int k = 0; k < 4; ++k)
        {
            int i = cur_i + dires[k];
            int j = cur_j + dires[k + 1];
            if(i >= 0 && i < m && j >= 0 && j < n && word[depth] == board[i][j] && !visit[i][j])
            {
                visit[i][j] = 1;
                bool ok = dfs(board, i, j, depth + 1, arrive, word);
                visit[i][j] = 0;
                if(ok)
                    return true;
                
            }
        }

        return false;
    }
};