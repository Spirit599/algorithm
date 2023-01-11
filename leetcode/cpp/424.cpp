class Solution {
public:
    int characterReplacement(string s, int k) {

        int memo[26];
        memset(memo, 0, sizeof(memo));

        function<bool()> check = [&]() ->bool {

            int maxx = 0;
            int sum = 0;
            for(int i = 0; i < 26; ++i)
            {
                sum += memo[i];
                maxx = max(maxx, memo[i]);
            }
            return sum - maxx <= k;
        };

        int n = s.size();
        int ans = 0;
        int left = -1;
        for(int right = 0; right < n; ++right)
        {
            ++memo[s[right] - 'A'];
            while(!check())
            {
                ++left;
                --memo[s[left] - 'A'];
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};