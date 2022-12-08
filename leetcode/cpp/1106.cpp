class Solution {
public:
    bool parseBoolExpr(string expression) {

        vector<char> stk;
        int n = expression.size();

        int i = 0;
        while(i < n)
        {
            char c = expression[i];
            if(c == ',')
                ;
            else if(c != ')')
                stk.emplace_back(c);
            else
            {
                int t = 0;
                int f = 0;
                while(stk.back() != '(')
                {
                    if(stk.back() == 't')
                        ++t;
                    else
                        ++f;
                    stk.pop_back();
                }
                stk.pop_back();
                char opt = stk.back();
                stk.pop_back();
                char add;
                if(opt == '!')
                {
                    if(t == 1)
                        add = 'f';
                    else
                        add = 't';
                }
                else if(opt == '&')
                {
                    if(f > 0)
                    {
                        add = 'f';
                    }
                    else
                        add = 't';
                }
                else if(opt == '|')
                {
                    if(t > 0)
                        add = 't';
                    else
                        add = 'f';
                }
                stk.emplace_back(add);
            }
            ++i;
        }

        return stk.back() == 't';
    }
};