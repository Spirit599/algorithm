class Solution {
public:
    int maxPower(string s) {

        int cur = 0;
        int ans = 1;
        char pre_ch = ' ';

        for(char ch : s)
        {
            if(ch == pre_ch)
            {
                ++cur;
                ans = max(ans, cur);
            }
            else
            {
                cur = 1;
                pre_ch = ch;
            }
        }

        return ans;

    }
};