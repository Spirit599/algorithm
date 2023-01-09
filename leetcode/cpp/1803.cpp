const int HighBit = 14;

class Trie
{
public:
    class TrieNode
    {
    public:
        int sum;
        TrieNode* children[2];
        TrieNode()
        {
            sum = 0;
            memset(children, 0, sizeof(children));
        }
        ~TrieNode();
    };
    TrieNode* root = new TrieNode();
    void insert(int num) 
    {
        TrieNode* p = root;
        for(int i = HighBit; i >= 0; --i)
        {
            int next = (num >> i) & 1;
            if(!p->children[next])
                p->children[next] = new TrieNode();
            p = p->children[next];
            ++(p->sum);
        }
    }
    int query(int x, int val)
    {
        TrieNode* p = root;
        int ret = 0;
        for(int i = HighBit; i >= 0; --i)
        {
            int k = (x >> i) & 1;
            if((val >> i) & 1)
            {
                if(p->children[k])
                    ret += p->children[k]->sum;
                if(!p->children[k ^ 1])
                    return ret;
                p = p->children[k ^ 1];
            }
            else
            {
                if(!p->children[k])
                    return ret;
                p = p->children[k];
            }
        }

        ret += p->sum;
        return ret;
    }

};

class Solution {
public:

    int helper(vector<int>& nums, int val) {

        int n = nums.size();
        int ret = 0;
        Trie trie;
        for(int i = 1; i < n; ++i)
        {
            trie.insert(nums[i - 1]);
            ret += trie.query(nums[i], val);
        }
        return ret;
    }

    int countPairs(vector<int>& nums, int low, int high) {


        return helper(nums, high) - helper(nums, low - 1);
    }
};