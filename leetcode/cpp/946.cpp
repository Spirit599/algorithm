class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int j = 0;
        int n = pushed.size();
        vector<int> stk;
        for(int i = 0; i < n; ++i)
        {
            stk.emplace_back(pushed[i]);
            while(!stk.empty() && popped[j] == stk.back())
            {
                ++j;
                stk.pop_back();
            }
        }

        return stk.empty();
    }
};