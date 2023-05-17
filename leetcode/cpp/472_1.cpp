typedef unsigned long long ull;
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        set<ull> memo;
        // ull hashCode = 0;
        ull base = 131;

        for(string& word : words)
        {
            ull hashCode = 0;
            int n = words.size();
            for(char c : word)
            {
                hashCode = base * hashCode + c;
            }
            memo.insert(hashCode);
        }


        ull preHashCode[35];
        ull power[35];
        vector<string> ret;
        for(string& word : words)
        {
            int n = word.size();

            preHashCode[0] = 0;
            power[0] = 1;

            for(int i = 0; i < n; ++i)
            {
                preHashCode[i + 1] = preHashCode[i] * base + word[i];
                power[i + 1] = power[i] * base;
            }

            int dp[n + 1];
            memset(dp, -1, sizeof(dp));
            dp[0] = 0;

            for(int i = 1; i <= n; ++i)
            {
                for(int j = 0; j < i; ++j)
                {
                    if(dp[j] == -1)
                        continue;

                    //i - 1 到 j
                    ull hashCode = preHashCode[i] - power[i - j] * preHashCode[j];

                    if(memo.count(hashCode))
                    {
                        dp[i] = max(dp[i], dp[j] + 1);
                        if(dp[j] > 1)
                            break;
                    } 
                }
            }

            if(dp[n] > 1)
            {
                ret.push_back(word);
            }


        }


        
        return ret;
    }
};