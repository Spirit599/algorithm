class Solution {
public:
    string reorganizeString(string s) {

        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        int maxx = 0;

        for(char c : s)
        {
            ++cnt[c - 'a'];
            maxx = max(maxx, cnt[c - 'a']);
        }

        int n = s.size();
        if(maxx > (n + 1) / 2)
            return "";

        string ans(n, ' ');
        int oddIndex = 1;
        int evenIndex = 0;
        int half = n / 2;

        for(int i = 0; i < 26; ++i)
        {
            if(cnt[i] <= half)
            {
                while(cnt[i] && oddIndex < n)
                {
                    ans[oddIndex] = 'a' + i;
                    --cnt[i];
                    oddIndex += 2;
                }
            }

            while(cnt[i])
            {
                ans[evenIndex] = 'a' + i;
                --cnt[i];
                evenIndex += 2;
            }
        }

        return ans;
    }
};