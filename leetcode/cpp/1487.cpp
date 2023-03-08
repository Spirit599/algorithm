class Solution {
public:
    string addSuffix(string& name, int k) {
        return name + "(" + to_string(k) + ")";
    }
    vector<string> getFolderNames(vector<string>& names) {

        unordered_map<string, int> memo;
        vector<string> ans;

        for(string& str : names)
        {
            if(memo.count(str) == 0)
            {
                memo[str] = 1;
                ans.push_back(str);
            }
            else
            {
                int k = memo[str];
                while(memo.count(addSuffix(str, k)) == 1)
                    ++k;
                ans.push_back(addSuffix(str, k));
                memo[str] = k + 1;
                memo[addSuffix(str, k)] = 1;
            }
        }

        return ans;
    }
};