class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = shifts.size();
        int diff[n + 1];
        memset(diff, 0, sizeof(diff));

        for(auto& shift : shifts)
        {
            int add = 2 * shift[2] - 1;
            diff[shift[0]] += add;
            diff[shift[1] + 1] -= add;
        }

        string ans(n, ' ');
        int cur = 0;
        for(int i = 0; i < n; ++i)
        {
            cur = (cur + diff[i]) % 26 + 26;
            ans[i] = (s[i] - 'a' + cur) % 26 + 'a';
        }

        return ans;

    }
};