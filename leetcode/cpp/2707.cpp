
class Trie
{
private:
    class TrieNode {
    public:
        bool isEnd;
        TrieNode* children[26];
        TrieNode()
        {
            isEnd = false;
            memset(children, 0, sizeof(children));
        }
    };

    TrieNode root;
public:
    void insert(const string& word)
    {
        TrieNode* p = &root;
        for(char c : word)
        {
            int next = c - 'a';
            if(!p->children[next])
                p->children[next] = new TrieNode();
            p = p->children[next];
        }
        p->isEnd = true;
    }

    vector<int> fixLength(const string& word)
    {
        TrieNode* p = &root;
        vector<int> ret;
        int len = 0;
        for(char c : word)
        {
            ++len;
            int next = c - 'a';
            if(!p->children[next])
                return ret;
            p = p->children[next];
            if(p->isEnd)
                ret.push_back(len);
        }
        return ret;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        Trie trie;
        for(const string& word : dictionary)
            trie.insert(word);

        int n = s.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; ++i)
        {
            vector<int> fixLen = trie.fixLength(s.substr(i));
            for(int len : fixLen)
            {
                int endIdx = i + len;
                dp[endIdx] = max(dp[endIdx], dp[i] + len);
            }
            for(int i = 0; i < n; ++i)
                dp[i + 1] = max(dp[i + 1], dp[i]);
        }

        return n - dp[n];
    }
};

