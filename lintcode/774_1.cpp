// 774 · 重复的DNA

class Solution {
public:
    /**
     * @param s: a string represent DNA sequences
     * @return: all the 10-letter-long sequences 
     *          we will sort your return value in output
     */
    vector<string> findRepeatedDna(string &s) {
        
        unordered_map<string, int> memo;
        vector<string> ans;
        int n = s.size();

        for(int i = 0; i + 9 < n; ++i)
        {
            ++memo[s.substr(i, 10)];
        }

        for(auto& kav : memo)
            if(kav.second > 1)
                ans.push_back(std::move(kav.first));

        return ans;
    }
};