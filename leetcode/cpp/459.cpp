// kmp

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n = s.size();
        int pi[n];
        getPiArray(s, pi);

        int border = pi[n - 1];
        // printf("%d\n", border);
        int minT = n - border;
        if(n != minT && n % minT == 0)
            return true;
        return false;
    }
    void getPiArray(const string& s, int pi[]) {

        pi[0] = 0;
        int n = s.size();
        for(int i = 1; i < n; ++i)
        {
            int j = pi[i - 1];
            while(j > 0 && s[j] != s[i])
                j = pi[j - 1];
            if(s[i] == s[j])
                ++j;
            pi[i] = j;
        }
    }
};