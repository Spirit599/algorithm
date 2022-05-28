class Solution {
public:
    /**
     * @param names: a string array
     * @return: a string array
     *          we will sort your return value in output
     */
    vector<string> nameDeduplication(vector<string> &names) {
        
        set<string> memo;
        for(string& str : names)
        {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            memo.insert(str);
        }

        vector<string> ans;
        for(auto& str : memo)
            ans.emplace_back(str);

        return ans;
    }
};