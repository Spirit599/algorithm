class Trie {
private:
    class TrieNode {
    public:
        TrieNode* children[27];
        int idx;
        TrieNode() {
            memset(children, 0, sizeof(children));
            idx = -1;
        }
    };
    int charConvertToInt(char c) {

        if(islower(c))
            return c - 'a';
        return 26;
    }
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string& str, int start, int idx) {

        int end = str.size() - 1;
        TrieNode* p = root;
        for(int i = start; i <= end; ++i)
        {
            int next = charConvertToInt(str[i]);
            if(p->children[next] == nullptr)
            {
                p->children[next] = new TrieNode();
            }
            p->children[next]->idx = idx;
            p = p->children[next];
        }
    }

    int search(string& str) {

        int end = str.size() - 1;
        TrieNode* p = root;
        for(int i = 0; i <= end; ++i)
        {
            int next = charConvertToInt(str[i]);
            if(p->children[next] == nullptr)
                return -1;
            p = p->children[next];
        }
        return p->idx;
    }
};

class WordFilter {
public:
    Trie trie;
    WordFilter(vector<string>& words) {

        int n = words.size();
        for(int i = 0; i < n; ++i)
        {
            string insertStr(words[i] + "#" + words[i]);
            int j = 0;
            while(1)
            {
                trie.insert(insertStr, j, i);
                if(insertStr[j] == '#')
                    break;
                ++j;
            }
        }
    }
    
    int f(string pref, string suff) {

        string findStr(suff + "#" + pref);
        return trie.search(findStr);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */