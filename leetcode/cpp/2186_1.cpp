class Solution {
public:
    int minSteps(string s, string t) {
        
        int s_hash[26];
        memset(s_hash, 0, sizeof(s_hash));
        int t_hash[26];
        memset(t_hash, 0, sizeof(t_hash));

        for(char c : s)
            ++s_hash[c - 'a'];
        for(char c : t)
            ++t_hash[c - 'a'];

        int diff = 0;
        for (int i = 0; i < 26; ++i)
        {
            diff += abs(s_hash[i] - t_hash[i]);
        }

        return diff;
    }
};