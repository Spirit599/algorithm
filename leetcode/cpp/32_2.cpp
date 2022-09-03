// 32. 最长有效括号

class Solution {
public:
    int longestValidParentheses(string s) {

    	int ans = 0;
        stack<int> sta;
        sta.push(-1);
        int n = s.size();

        for(int i = 0; i < n; ++i)
        {
            if(s[i] == ')')
            {
                sta.pop();
                if(sta.empty())
                    sta.push(i);
                else
                    ans = max(ans, i - sta.top());
            }
            else // s[i] == '('
            {
                sta.push(i);
            }
        }

    	return ans;
    }
};