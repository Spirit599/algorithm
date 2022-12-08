// 栈

class Solution {
public:
    int calculate(string s) {

        vector<int> numStk;
        vector<int> optStk;
        int n = s.size();
        int i = 0;
        int sign = 1;
        int ans = 0;
        while(i < n)
        {
            
            if(isdigit(s[i]))
            {
                int num = 0;
                while(i < n && isdigit(s[i]))
                {
                    num = 10 * num - '0' + s[i];
                    ++i;
                }
                --i;
                ans += sign * num;
            }
            else if(s[i] == '(')
            {
                numStk.emplace_back(ans);
                optStk.emplace_back(sign);
                ans = 0;
                sign = 1;
            }
            else if(s[i] == '+')
            {
                sign = 1;
            }
            else if(s[i] == '-')
            {
                sign = -1;
            }
            else if(s[i] == ')')
            {
                ans = numStk.back() + ans * optStk.back();
                numStk.pop_back();
                optStk.pop_back();
            }
            ++i;
        }

        return ans;
    }
};