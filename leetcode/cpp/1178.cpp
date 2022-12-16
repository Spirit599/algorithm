class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

        unordered_map<int, int> dp;
        for(string& str : words)
        {
            int mask = 0;
            for(char c : str)
                mask |= (1 << (c - 'a'));
            if(__builtin_popcount(mask) <= 7)
                ++dp[mask];
        }

        vector<int> ans;
        for(string& str : puzzles)
        {
            int sum = 0;
            int mask = 0;
            for(int i = 1; i < 7; ++i)
                mask |= (1 << (str[i] - 'a'));

            int subset = mask;
            while(1)
            {
                int s = subset | (1 << (str[0] - 'a'));
                auto it = dp.find(s);
                if(it != dp.end())
                    sum += it->second;

                subset = (subset - 1) & mask;
                if(subset == mask)
                    break;
            }
            ans.emplace_back(sum);
        }

        return ans;
    }
};