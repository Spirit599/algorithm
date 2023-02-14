class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        unordered_map<char, bool> isVowel;
        isVowel['a'] = true;
        isVowel['e'] = true;
        isVowel['i'] = true;
        isVowel['o'] = true;
        isVowel['u'] = true;

        int n = words.size();
        int preSum[n + 1];
        preSum[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            string& str = words[i];
            if(isVowel[str.front()] && isVowel[str.back()])
                preSum[i + 1] = preSum[i] + 1;
            else
                preSum[i + 1] = preSum[i];
        }

        int qs = queries.size();
        vector<int> ans(qs);
        for(int i = 0; i < qs; ++i)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            ans[i] = preSum[y + 1] - preSum[x];
        }

        return ans;
    }
};