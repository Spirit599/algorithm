class Solution {
public:
    int ret = 0;
    int maxProduct(string s) {
        
        string s1;
        string s2;
        int index = 0;
        dfs(s, s1, s2, index);
        return ret;
    }

    void dfs(const string& s, string& s1, string& s2, int index) {

        if(check(s1) && check(s2))
            ret = max(ret, int(s1.size() * s2.size()));

        if(index == s.size())
            return ;
        s1.push_back(s[index]);

        dfs(s, s1, s2, index + 1);

        s1.pop_back();
        s2.push_back(s[index]);

        dfs(s, s1, s2, index + 1);

        s2.pop_back();

        dfs(s, s1, s2, index + 1);

        return ;
    }

    bool check(const string& str)
    {
        for (int i = 0; i < str.size() / 2; ++i)
        {
            /* code */
            if(str[i] != str[str.size() - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};