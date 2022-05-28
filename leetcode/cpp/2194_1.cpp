class Solution {
public:
    vector<string> cellsInRange(string s) {
        
        int s0 = s[0];
        int n0 = s[1];
        int s1 = s[3];
        int n1 = s[4];
        vector<string> ans;

        for(int i = s0; i <= s1; ++i)
        {
            for(int j = n0; j <= n1; ++j)
            {
                string tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};