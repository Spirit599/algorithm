// 212. 单词搜索 II
// TLE
class TrieNode {
public:
    bool isEnd;
    TrieNode* next[26];
    TrieNode() {
        isEnd = true;
        memset(next, 0 , sizeof(next));
    }
};


int dires[] = {-1, 0, 1, 0, -1};

class Solution {
public:
    bool vis[40000];
    int m;
    int n;
    

    void dfs(int i, int j, TrieNode* p, vector<vector<char>>& board)
    {
        int index = board[i][j] - 'a';
        if(p->next[index] == nullptr)
        {
            p->next[index] = new TrieNode();
        }
        for(int k = 0; k < 4; ++k)
        {
            int ii = i + dires[k];
            int jj = j + dires[k + 1];
            int mapping = ii * 200 + jj;
            if(ii < 0 || ii >= m || jj < 0 || jj >= n || vis[mapping])
                continue;
            vis[mapping] = true;
            dfs(ii, jj, p->next[index], board);
            vis[mapping] = false;
        }
    }

    bool find(TrieNode* p, string& str)
    {
        for(char c : str)
        {
            int index = c - 'a';
            if(p->next[index] != nullptr)
                p = p->next[index];
            else
                return false;
        }
        return true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        TrieNode root;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                memset(vis, 0, sizeof(vis));
                int mapping = i * 200 + j;
                vis[mapping] = true;
                dfs(i, j, &root, board);
                printf("%d %d\n", i,j);
            }
        }

        printf("finish\n");

        vector<string> ans;
        for(string& str : words)
        {
            if(find(&root, str))
                ans.push_back(str);
        }
        return ans;
    }
};