class Solution {
public:
    int minimumScore(string s, string t) {
        
        int ns = s.size();
        int nt = t.size();
        int pre[nt];
        int suf[nt];
        memset(pre, 0x3f, sizeof(pre));
        memset(suf, 0x3f, sizeof(suf));
        int inVaild = 0x3f3f3f3f;

        int idx = 0;
        for(int i = 0; i < nt; ++i)
        {
            while(idx < ns && s[idx] != t[i])
                ++idx;
            if(idx < ns)
            {
                pre[i] = idx;
                ++idx;
            }
        }

        idx = ns - 1;
        for(int i = nt - 1; i >= 0; --i)
        {
            while(idx >= 0 && s[idx] != t[i])
                --idx;

            if(idx >= 0)
            {
                suf[i] = idx;
                --idx;
                
            }
        }

        // if(pre[0] <= suf[0])
        //     return 0;
        int ans = nt;
        for(int i = 0; i < nt; ++i)
            if(suf[i] != inVaild)
                ans = min(ans, i);
        for(int i = nt - 1; i >= 0; --i)
            if(pre[i] != inVaild)
                ans = min(ans, nt - i - 1);

        
        int left = 0;
        for(int right = 0; right < nt; ++right)
        {
            if(suf[right] == inVaild)
                continue;
            while(pre[left] < suf[right])
            {
                if(left == right)
                    return 0;
                ans = min(ans, right - left - 1);
                ++left;
            }
        }

        return ans;
    }
};