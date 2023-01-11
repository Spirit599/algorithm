// 212. 单词搜索 II

class TrieNode {
public:
    bool isEnd;
    TrieNode* next[26];
    TrieNode() {
        isEnd = false;
        memset(next, 0 , sizeof(next));
    }
};


int dires[] = {-1, 0, 1, 0, -1};

class Solution {
public:

    unordered_set<string> ans;
    bool vis[40000];
    int m;
    int n;

    void insert(TrieNode* p, const string& str)
    {
        for(char c : str)
        {
            int index = c - 'a';
            if(p->next[index] == nullptr)
                p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->isEnd = true;
    }

    void dfs(TrieNode* p,int i, int j, vector<vector<char>>& board, string& cur)
    {
        // printf("i = %d j = %d cur = %s\n", i,j,cur.c_str());


        int mapping = i * 200 + j;
        //cout<<vis[mapping]<<endl;
        if(i < 0 || i >= m || j < 0 || j >= n || vis[mapping])
                return;

        // printf("i = %d j = %d cur = %s\n", i,j,cur.c_str());

        int index = board[i][j] - 'a';
        if(p->next[index] == nullptr)
        {
            return ;
        }

        vis[mapping] = true;
        p = p->next[index];
        cur.push_back(board[i][j]);

        if(p->isEnd)
        {
            //cout<<cur<<endl;
            ans.insert(cur);
        }


        for(int k = 0; k < 4; ++k)
        {
            int ii = i + dires[k];
            int jj = j + dires[k + 1];
            dfs(p, ii, jj, board, cur);
            
        }

        cur.pop_back();
        vis[mapping] = false;       
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        TrieNode root;
        m = board.size();
        n = board[0].size();
        

        for(string& str :words)
            insert(&root, str);

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                string cur;
                memset(vis, 0, sizeof(vis));
                // printf("%d %d\n", i,j);
                dfs(&root, i, j, board, cur);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};