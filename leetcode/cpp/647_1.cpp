// 647. 回文子串

class Solution {
public:
    int countSubstrings(string s) {

        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            //i在字符串中间
            ++ans;
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right])
            {
                ++ans;
                ++right;
                --left;
            }

            //i不在中间 a(a)aa
            if(i + 1 < n && s[i] == s[i + 1])
            {
                ++ans;
                int left = i - 1;
                int right = i + 2;
                while(left >= 0 && right < n && s[left] == s[right])
                {
                    ++ans;
                    ++right;
                    --left;
                }
            }
        }

        return ans;
    }
};