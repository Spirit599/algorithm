class Solution {
public:
    bool checkPartitioning(string s) {

        int n = s.size();
        bool isPali[n][n];
        memset(isPali, 0, sizeof(isPali));
        for(int i = 0; i < n; ++i)
        {
            isPali[i][i] = true;
            if(i && s[i] == s[i - 1])
                isPali[i - 1][i] = true;
        }

        for(int len = 3; len <= n; ++len)
        {
            for(int start = 0; start + len - 1 < n; ++start)
            {
                int end = start + len - 1;
                if(s[start] == s[end] && isPali[start + 1][end - 1])
                    isPali[start][end] = true;

            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(isPali[0][i] && isPali[i + 1][j - 1] && isPali[j][n - 1])
                    return true;
            }
        }

        return false;
    }
};