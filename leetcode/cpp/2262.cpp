class Solution {
public:
    long long appealSum(string s) {
        
        int pre[26];
        memset(pre, -1, sizeof(pre));

        long long ans = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            ans += 1ll * (i - pre[s[i] - 'a']) * (n - i);
            pre[s[i] - 'a'] = i;
        }
        return ans;
    }
};