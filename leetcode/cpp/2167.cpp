class Solution {
public:
    int minimumTime(string s) {

        int n = s.size();
        int left[n + 1];
        memset(left, 0, sizeof(left));
        int right[n + 1];
        memset(right, 0, sizeof(right));

        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '0')
                left[i + 1] = left[i];
            else
                left[i + 1] = min(i + 1, left[i] + 2);
        }

        for(int i = n - 1; i >= 0; --i)
        {
            if(s[i] == '0')
                right[i] = right[i + 1];
            else
                right[i] = min(right[i + 1] + 2, n - i);
        }

        int ans = n;
        for(int i = 0; i < n; ++i)
            ans = min(ans, left[i] + right[i]);
        return ans;
    }

};