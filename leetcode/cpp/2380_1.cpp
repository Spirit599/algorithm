class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int cnt0 = 0;
        int slen = s.size();
        int ans = 0;

        for(int i = 0; i < slen; ++i)
        {
            if(s[i] == '0')
                ++cnt0;
            else if(cnt0 > 0)
                ans = max(ans + 1, cnt0);
        }

        return 
    }
};