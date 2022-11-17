class Solution {
public:
    vector<int> partitionLabels(string s) {

        int last[26];
        memset(last, -1, sizeof(last));
        int n = s.size();

        for(int i = 0; i < n; ++i)
            last[s[i] - 'a'] = i;

        
        int end = -1;
        int cur = 0;
        vector<int> ans;
        for(int i = 0; i < n; ++i)
        {
            end = max(end, last[s[i] - 'a']);
            ++cur;
            if(end == i)
            {
                ans.push_back(cur);
                cur = 0;
            }
        }
        return ans;
    }
};