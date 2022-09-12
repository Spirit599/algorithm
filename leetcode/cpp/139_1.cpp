// 139.单词拆分

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

            unordered_set<string> memo;
            for(string& word : wordDict)
            {
                reverse(word.begin(), word.end());
                memo.insert(word);
            }

            int n = s.size();
            bool dp[n + 1];
            memset(dp, 0, sizeof(dp));
            dp[0] = true;

            for(int i = 1; i <= n; ++i)
            {
                string cur;
                for(int j = i - 1; j >= 0; --j)
                {
                    cur.push_back(s[j]);
                    if(dp[j] && memo.count(cur))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }

            return dp[n];
    }
};