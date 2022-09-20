// 2375. 根据模式串构造最小数字

class Solution {
public:
    string smallestNumber(string pattern) {
        
        int n = pattern.size();
        string ans(n + 1, '0');
        char cur = '1';

        int i = 0;
        while(i < n)
        {
            if(pattern[i] == 'I')
                ans[i++] = cur++;
            else
            {
                int start = i;
                while(i < n && pattern[i] == 'D')
                {
                    ans[i++] = cur++;
                }
                ans[i++] = cur++;
                printf("%d %d\n", start, i);
                reverse(ans.begin() + start, ans.begin() + i);
            }
        }

        if(pattern[n - 1] == 'I')
            ans[n] = cur;
        return ans;
    }
};