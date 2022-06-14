//1335 · 重复的DNA序列

class Solution {
public:
    /**
     * @param s: a string
     * @return: return List[str]
     *          we will sort your return value in output
     */
    vector<string> findRepeatedDnaSequences(string &s) {
        
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