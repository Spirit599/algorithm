class Tire {
public:
    class Tirenode {
    public:
        Tirenode* next[26];
        bool isEnd;
        Tirenode() {
            memset(next, 0, sizeof(next));
            isEnd = false;
        }
    };
    Tirenode* root = new Tirenode();
    int cnt = 0;
    int sum = 0;

    void insert(const string& str)
    {
        Tirenode* p = root;
        for(char c : str)
        {
            p->isEnd = false;
            int index = c - 'a';
            if(p->next[index] == nullptr)
                p->next[index] = new Tirenode();
            p = p->next[index];
        }
        p->isEnd = true;
    }

    void dfs(Tirenode* p, int depth)
    {
        if(p->isEnd)
        {
            ++cnt;
            sum += depth;
            return ;
        }
        for(int i = 0; i < 26; ++i)
        {
            if(p->next[i])
            {
                dfs(p->next[i], depth + 1);
            }
        }
    }

};
struct cmpStr
{
    bool operator() (const string& s1, const string& s2)
    {
        return s1.size() < s2.size();
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Tire trie;
        sort(words.begin(), words.end(), cmpStr());
        for(string word : words)
        {
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
        trie.dfs(trie.root, 0);
        //printf("%d %d\n", trie.sum, trie.cnt);
        return trie.sum + trie.cnt;
    }
};
