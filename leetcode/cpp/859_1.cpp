const int MAX_HASH = 26;

class Solution {
public:
    bool buddyStrings(string s, string goal) {

        int n = s.size();
        int m = goal.size();
        if(n != m)
            return false;

        int memo[MAX_HASH];
        memset(memo, 0, sizeof(memo));

        int diff = 0;
        char s_diff = ' ';
        char goal_diff = ' ';
        for (int i = 0; i < n; ++i)
        {
            if(s[i] != goal[i])
            {
                ++diff;
                if(diff == 1)
                {
                    s_diff = s[i];
                    goal_diff = goal[i];
                }
                else if(diff == 2)
                {
                    if(s_diff != goal[i] || goal_diff != s[i])
                        return false;
                }
                if(diff > 2)
                    return false;
            }

            ++memo[s[i] - 'a'];
        }

        if(diff == 2)
            return true;
        else if(diff == 1)
            return false;
        else
        {
            for (int i = 0; i < MAX_HASH; ++i)
            {
                if(memo[i] >= 2)
                    return true;
            }
            return false;
        }
    }
};