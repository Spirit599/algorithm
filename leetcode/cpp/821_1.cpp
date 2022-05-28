class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        int n = s.size();
        vector<int> ans(n);

        int index = -(n + 1);
        for (int i = 0; i < n; ++i)
        {
            if(s[i] == c)
            {
                index = i;
            }
            ans[i] = i - index;
        }

        index = 2 * n + 1;
        for(int i = n - 1; i >= 0; --i)
        {
            if(s[i] == c)
            {
                index = i;
            }
            ans[i] = min(ans[i], index - i);
        }

        return ans;


    }
};