// 后缀数组
// sa rk
// n(logn)^2
typedef unsigned long long ull; 
class Solution {
public:
    string longestDupSubstring(string s) {

        int n = s.size();
        ull hash[n + 1];
        ull power[n + 1];
        hash[0] = 0;
        power[0] = 1;
        ull base = 131;
        int sa[n];
        int rk[n];
        

        for(int i = 0; i < n; ++i)
        {
            hash[i + 1] = (hash[i] * base + s[i]);
            power[i + 1] = (power[i] * base);
            //cout<<hash[i + 1]<<" "<<power[i + 1]<<endl;
            sa[i] = i;
        }

        function<ull(int, int)> getHashCode = [&](int start, int end) -> ull {

            return (hash[end + 1] - hash[start] * power[end - start + 1]);
        };

        function<bool(int, int, int)> check = [&](int x, int y, int len) -> bool {

            //printf("%d %d %d %d\n", x, x + len - 1, y, y + len - 1);
            if(getHashCode(x, x + len - 1) == getHashCode(y, y + len - 1))
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        function<int(int, int)> getMaxPre = [&](int x, int y) -> int {

            int low = 0;
            int high = min(n - x, n - y);
            int ret = 0;
            while(low != high)
            {
                
                int len = (low + high + 1) >> 1;
                if(check(x, y, len))
                {
                    // printf("yes\n");
                    ret = len;
                    low = len;
                }
                else
                {
                    high = len - 1;
                }
            }

            //printf("%d %d %d\n", x,y,ret);

            return ret;
        };

        sort(sa, sa + n, [&](int x, int y) {
            int maxPre = getMaxPre(x, y);
            // printf("%d %d\n", x + maxPre, y + maxPre);
            return s[x + maxPre] < s[y + maxPre];}
        );

        int height[n];
        height[0] = 0;
        int length = 0;
        int index = 0;
        for(int i = 1; i < n; ++i)
        {
            height[i] = getMaxPre(sa[i - 1], sa[i]);
            if(height[i] > length)
            {
                length = height[i];
                index = sa[i];
            }
        }


        return s.substr(index, length);

    }
};