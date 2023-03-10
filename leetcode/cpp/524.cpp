// 序列自动机

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        sort(dictionary.begin(), dictionary.end(), [](auto& str1, auto& str2) {return str1.size() > str2.size() || (str1.size() == str2.size() && str1 < str2);});

        int next[26];
        memset(next, -1, sizeof(next));
        int n = s.size();
        int dp[n + 1][26];
        memset(dp[n], -1, sizeof(dp[n]));
        for(int i = n - 1; i >= 0; --i)
        {
            next[s[i] - 'a'] = i + 1;
            memcpy(dp[i], next, sizeof(dp[i]));
        }

        for(const string& str : dictionary)
        {
            int idx = 0;
            for(char c : str)
            {
                idx = dp[idx][c - 'a'];
                if(idx == -1)
                    break;
            }
            if(idx == -1)
                continue;
            return str;
        }
        return "";
    }
};