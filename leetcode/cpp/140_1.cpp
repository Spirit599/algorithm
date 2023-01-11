class TrieNode {
public:
    bool isEnd;
    TrieNode* next[26];
    TrieNode() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    TrieNode root;
    void insert(string word) {
        TrieNode *p = &root;
        for(char c : word) {
            int index = c - 'a';
            if(p->next[index] == nullptr)
                p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->isEnd = true;
    }
};

class Solution {
public:
    vector<string> ans;

    void dfs(string& s, int n, int depth, string& cur, TrieNode* p, TrieNode* root) {

        if(depth == n)
        {
            cout<<cur<<endl;
            if(cur.back() == ' ')
            {

                ans.push_back(cur.substr(0, cur.size() - 1));
            }
            return ;
        }
        int index = s[depth] - 'a';
        if(p->next[index] == nullptr)
            return ;

        p = p->next[index];
        cur.push_back(s[depth]);
        if(p->isEnd)
        {
            cur.push_back(' ');
            dfs(s, n, depth + 1, cur, root, root);
            cur.pop_back();
        }
        dfs(s, n, depth + 1, cur, p, root);
        cur.pop_back();

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        Trie trie;
        for(string& str : wordDict)
            trie.insert(str);

        string cur;
        int n = s.size();
        dfs(s, n, 0, cur, &(trie.root), &(trie.root));


        return ans;
    }
};