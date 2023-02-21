class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.size();
        bool isWrong[n];
        memset(isWrong, 0, sizeof(isWrong));

        vector<int> stk;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(')
            {
                stk.push_back(i);
                isWrong[i] = true;
            }
            else if(s[i] == ')')
            {
                if(!stk.empty())
                {
                    isWrong[stk.back()] = false;
                    stk.pop_back();
                }
                else
                {
                    isWrong[i] = true;
                }
            }
        }

        string ans;
        for(int i = 0; i < n; ++i)
        {
            if(!isWrong[i])
                ans.push_back(s[i]);
        }
        return ans;
    }
};