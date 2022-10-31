// 分治

class Solution {
public:
    int dp[31][31][31];
    bool isScramble(string s1, string s2) {

        memset(dp, -1, sizeof(dp));
        return isScrambleHelper(s1, s2, 0, s1.size(), 0, s2.size());
    }
    bool isScrambleHelper(const string& s1, const string& s2,
                            int s1Left, int s1Right,
                            int s2Left, int s2Right)
    {
        int n = s1Right - s1Left;
        if(dp[s1Left][s2Left][n] != -1)
            return dp[s1Left][s2Left][n];

        
        if(n == 1)
            return s1[s1Left] == s2[s2Left];

        for(int i = 1; i < n; ++i)
        {
            if(isScrambleHelper(s1, s2, s1Left, s1Left + i, s2Left, s2Left + i) &&
                isScrambleHelper(s1, s2, s1Left + i, s1Right, s2Left + i, s2Right))
                return dp[s1Left][s2Left][n] = true;
            if(isScrambleHelper(s1, s2, s1Left, s1Left + i, s2Right - i, s2Right) &&
                isScrambleHelper(s1, s2, s1Left + i, s1Right, s2Left, s2Right - i))
                return dp[s1Left][s2Left][n] = true;
        }
        return dp[s1Left][s2Left][n] = false;
    }
};