class Trie
{
public:
    class TrieNode
    {
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

    void insert(const string& word)
    {
        TrieNode* p = &root;
        for(char c : word)
        {
            int next = c - 'a';
            if(p->children[next] == nullptr)
                p->children[next] = new TrieNode();
            p = p->children[next];
        }
        p->isEnd = true;
    }

    bool find(const string& word)
    {
        TrieNode* p = &root;
        int n = word.size();
        for(int i = n - 1; i >= 0; --i)
        {
            char c = word[i];
            int next = c - 'a';
            if(p->children[next] == nullptr)
                return false;
            p = p->children[next];
            if(p->isEnd)
                return true;
        }

        return false;
    }
    
};

class StreamChecker {
public:
    Trie trie;
    string word;
    StreamChecker(vector<string>& words) {

        for(auto& str : words)
        {
            reverse(str.begin(), str.end());
            trie.insert(str);
        }
    }
    
    bool query(char letter) {
        
        word.push_back(letter);
        return trie.find(word);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */