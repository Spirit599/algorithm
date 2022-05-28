//进制

class Solution {
public:
    string convertToBase7(int num) {

        if(num == 0)
            return "0";

        string ans;
        if(num < 0)
        {
            ans.push_back('-');
            num *= -1;
        }

        while(num)
        {
            ans.push_back(num % 7 + '0');
            num = num / 7;
        }
        if(ans[0] == '-')
            reverse(ans.begin() + 1, ans.end());
        else
            reverse(ans.begin(), ans.end());
        return ans;
    }
};