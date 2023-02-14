class Trie
{
public:
    class TrieNode
    {
    public:
        bool isEnd;
        TrieNode* children[26];
        TrieNode() {
            isEnd = false;
            memset(children, 0, sizeof(children));
        }
    };
    TrieNode root;
    void insert(string& word) {

        TrieNode* p = &root;
        for(char c : word)
        {
            int idx = c - 'a';
            if(p->children[idx] == nullptr)
                p->children[idx] = new TrieNode();
            p = p->children[idx];
        }
        p->isEnd = true;
    }
    string getLongest() {

        TrieNode* p = &root;
        string cur;
        string ret;

        function<void(string&, TrieNode*)> dfs = [&](string& cur, TrieNode* p) -> void {

            bool haveNext = false;
            for(int i = 0; i < 26; ++i)
            {
                if(p->children[i])
                {
                    haveNext = true;
                    if(p->children[i]->isEnd)
                    {
                        cur.push_back('a' + i);
                        dfs(cur, p->children[i]);
                        cur.pop_back();
                    }
                }
            }

            if(cur.size() > ret.size())
                ret = cur;
            
        };

        for(int i = 0; i < 26; ++i)
        {
            if(p->children[i] && p->children[i]->isEnd)
            {
                cur.push_back('a' + i);
                dfs(cur, p->children[i]);
                cur.pop_back();
            }
        }
        return ret;
    }
    
};


class Solution {
public:
    string longestWord(vector<string>& words) {

        Trie trie;
        for(string& str : words)
            trie.insert(str);
        return trie.getLongest();
    }
};