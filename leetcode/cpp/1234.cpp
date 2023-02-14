class Solution {
public:
    int balancedString(string s) {

        int n = s.size();
        int ans = n;
        int m = n / 4;
        int cnt['Z'];
        memset(cnt, 0, sizeof(cnt));

        for(char c : s)
            ++cnt[c];

        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m)
            return 0;

        int left = 0;
        for(int right = 0; right < n; ++right)
        {
            --cnt[s[right]];
            while(cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m)
            {
                ans = min(ans, right - left + 1);
                printf("%d %d\n", right, left);
                ++cnt[s[left++]];
            }
        }

        return ans;
    }
};