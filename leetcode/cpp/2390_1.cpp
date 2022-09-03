class Solution {
public:
    string removeStars(string s) {
        
        int slen = s.size();
        string ans;
        int cnt = 0;
        for(int i = slen - 1; i >= 0; --i)
        {
            if(s[i] == '*')
            {
                ++cnt;
            }
            else
            { 
                if(cnt)
                    ;
                else
                    ans.push_back(s[i]);
                cnt = max(0, cnt - 1);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};