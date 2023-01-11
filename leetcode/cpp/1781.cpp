class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int cnt[26];

        auto getDif = [&]() -> int {

            int maxx = 0;
            int minn = 0;
            for(int i = 0; i < 26; ++i)
            {
                if(cnt[i] != 0)
                {
                    maxx = cnt[i];
                    minn = cnt[i];
                }
            }
            for(int i = 0; i < 26; ++i)
            {
                if(cnt[i] == 0)
                    continue;
                maxx = max(maxx, cnt[i]);
                minn = min(minn, cnt[i]);
            }
            return maxx - minn;
        };

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            memset(cnt, 0, sizeof(cnt));
            for(int j = i; j < n; ++j)
            {
                ++cnt[s[j] - 'a'];
                ans += getDif();
            }
        }

        return ans;
    }
};