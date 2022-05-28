class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        
        stack<char> sta;

        for(char c : s)
        {
            if(c == '(')
                sta.emplace(c);
            else if(c == '[')
                sta.emplace(c);
            else if(c == '{')
                sta.emplace(c);

            else if(c == ')')
            {
                if(sta.top() != '(')
                    return false;
                else
                    sta.pop();
            }
            else if(c == ']')
            {
                if(sta.top() != '[')
                    return false;
                else
                    sta.pop();
            }
            else if(c == '}')
            {
                if(sta.top() != '{')
                    return false;
                else
                    sta.pop();
            }
        }

        return sta.size() == 0;
    }
};