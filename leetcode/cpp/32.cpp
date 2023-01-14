class Solution {
public:
    int longestValidParentheses(string s) {

    	vector<int> stk;
    	stk.emplace_back(-1);
    	int ans = 0;

    	int n = s.size();
    	for(int i = 0; i < n; ++i)
    	{
    		char c = s[i];
    		if(c == '(')
    		{
    			stk.emplace_back(i);
    		}
    		else
    		{
    			stk.pop_back();
    			if(stk.empty())
    				stk.emplace_back(i);
    			ans = max(ans, i - stk.back());
    		}
    	}

    	return ans;

    }
};