// kmp

class Solution {
public:
    string shortestPalindrome(string s) {

        int n = s.size();
        string ss = s;
        reverse(ss.begin(), ss.end());
        s += "#";
        s += ss;


        cout<<s<<endl;

        int allSize = s.size();
        int pi[allSize];
        getPiArray(s, pi);
        int add = n - pi[allSize - 1];

        return  ss.substr(0, add) + s.substr(0, n);
    }
    void getPiArray(string& s, int pi[])
    {
        int n = s.size();
        pi[0] = 0;
        for(int i = 1; i < n; ++i)
        {
            int j = pi[i - 1];
            while(j > 0 && s[i] != s[j])
                j = pi[j - 1];

            if(s[i] == s[j])
                ++j;
            pi[i] = j;
        }
    }
};