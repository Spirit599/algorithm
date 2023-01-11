// 哈希函数
// 字符串哈希
typedef unsigned long long ull;

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        ull preHash[n + 1];
        ull power[n + 1];
        ull sufHash[n + 1];
        preHash[0] = 0;
        sufHash[n] = 0;
        power[0] = 1;
        ull base = 131;

        for(int i = 0; i < n; ++i)
        {
            preHash[i + 1] = preHash[i] * base + s[i];
            power[i + 1] = power[i] * base;
            sufHash[n - i - 1] = sufHash[n - i] * base + s[n - i - 1];
        }

        function<bool(int, int, int)> check = [&](int left, int right, int len) -> bool {

            if(len == 0)
                return true;
            ull leftHashCode = preHash[left + 1] - preHash[left - len + 1] * power[len];
            ull rightHashCode = sufHash[right] - sufHash[right + len] * power[len];
            if(leftHashCode == rightHashCode)
                return true;
            else
                return false;
        };

        function<int(int, int)> findMax = [&](int left, int right) -> int {

            int low = 0;
            int high = min(left + 1, n - right);
            while(low != high)
            {
                int len = (low + high + 1) >> 1;
                if(check(left, right, len))
                    low = len;
                else
                    high = len - 1;
            }
            return low;
        };


        int maxLen = 0;
        int index = -1;
        for(int i = 0; i < n; ++i)
        {
            int len1 = findMax(i, i);
            int realLen = 2 * len1 - 1;
            // printf("%d %d\n", i, realLen);
            if(realLen > maxLen)
            {
                maxLen = realLen;
                index = i - len1 + 1;
                // printf("%d\n", index);
            }
            if(i < n - 1)
            {
                int len2 = findMax(i, i + 1);
                int realLen = 2 * len2;
                if(realLen > maxLen)
                {
                    maxLen = realLen;
                    index = i - len2 + 1;
                }
            }

        }

        //printf("%d\n", maxLen);

        return s.substr(index, maxLen);
    }


};