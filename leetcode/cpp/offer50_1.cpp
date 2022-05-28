class Solution {
public:
    char firstUniqChar(string s) {

        int hash[26];
        memset(hash, 0, sizeof(hash));
        int n = s.size();
        for (int i = 0; i < n; ++i)
            ++hash[s[i] - 'a'];
        for (int i = 0; i < n; ++i)
        {
            if(hash[s[i] - 'a'] == 1)
                return s[i];
        }

        return ' ';
    }
};