class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int ans = 0;
        int n = s.size();
        for(int i = 0, j = n - 1; i < j; ++i)
        {
            int k = j;
            for(; i != k; --k)
            {
                if(s[k] == s[i])
                    break;
            }

            if(k != i)
            {
                for(; k != j; ++k)
                {
                    swap(s[k], s[k + 1]);
                    ++ans;
                }
                --j;
            }
            else
            {
                ans += n / 2 - i;
            }
        }

        return ans;
    }
};