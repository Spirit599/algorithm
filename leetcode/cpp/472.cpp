// 字符串哈希

typedef unsigned long long ull;
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        unordered_set<ull> memo;
        ull base = 131;
        int n = words.size();
        for(int i = 0; i < n; ++i)
        {
            int wordSize = words[i].size();
            ull wordHash = 0;
            for(int j = 0; j < wordSize; ++j)
            {
                wordHash = wordHash * base + words[i][j];
            }
            memo.insert(wordHash);
        }

        int maxLength = 35;
        ull hashCode[maxLength];
        ull power[maxLength];
        int dp[maxLength];
        vector<string> ret;
        for(int i = 0; i < n; ++i)
        {
            int wordSize = words[i].size();
            hashCode[0] = 0;
            power[0] = 1;
            
            for(int j = 0; j < wordSize; ++j)
            {
                hashCode[j + 1] = hashCode[j] * base + words[i][j];
                power[j + 1] = power[j] * base;
            }

            memset(dp, -1, sizeof(dp));
            dp[0] = 0;
            for(int j = 1; j <= wordSize; ++j)
            {
                for(int k = 0; k < j; ++k)
                {
                    if(dp[k] == -1)
                        continue;
                    ull pre = hashCode[j] - hashCode[k] * power[j - k];
                    if(memo.count(pre))
                    {
                        dp[j] = max(dp[j], dp[k] + 1);
                        if(dp[j] > 1)
                            break;
                    }
                }
                if(dp[wordSize] > 1)
                    ret.emplace_back(words[i]);
            }
        }

        
        return ret;
    }
};