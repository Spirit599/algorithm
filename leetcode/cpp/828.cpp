class Solution {
public:
    int uniqueLetterString(string s) {

        int n = s.size();
        int left[n];
        memset(left, -1, sizeof(left));
        int pre[26];
        memset(pre, -1, sizeof(pre));

        for(int i = 0; i < n; ++i)
        {
            left[i] = pre[s[i] - 'A'];
            pre[s[i] - 'A'] = i;
        }

        vector<int> suf(26, n);
        int ans = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            ans += (i - left[i]) * (suf[s[i] - 'A'] - i);
            suf[s[i] - 'A'] = i;
        }
        return ans;
    }
};