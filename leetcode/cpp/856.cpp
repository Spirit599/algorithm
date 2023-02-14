class Solution {
public:
    int scoreOfParentheses(string s) {

        vector<int> stk;
        stk.push_back(0);

        for(char c : s)
        {
            if(c == '(')
            {
                stk.push_back(0);
            }
            else
            {
                if(stk.back() == 0)
                    stk.back() = 1;
                else
                    stk.back() = 2 * stk.back();
                int val = stk.back();
                stk.pop_back();
                stk.back() += val;
            }
        }

        return stk[0];
    }
};