// 哈希函数

typedef unsigned long long ull;

class Solution {
public:
    string longestDupSubstring(string s) {

        int n = s.size();
        ull base = 31;
        ull hash[n + 1];
        ull power[n + 1];
        hash[0] = 0;
        power[0] = 1;
        for(int i = 0; i < n; ++i)
        {
            hash[i + 1] = hash[i] * base + s[i];
            power[i + 1] = power[i] * base;
        }

        unordered_set<ull> memo;

        function<int(int)> check = [&](int mid) -> int {
            
            if(mid == 0)
                return 0;
            memo.clear();
            for(int i = 1; i + mid - 1 <= n; ++i)
            {
                int j = i + mid - 1;
                ull hashCode = hash[j] - hash[i - 1] * power[j - i + 1];
                if(memo.count(hashCode) == 1)
                    return i - 1;
                memo.insert(hashCode);
            }

            return -1;
        };

        int high = s.size() - 1;
        int low = 0;
        int index = 0;
        while(low != high)
        {
            int mid = (low + high + 1) >> 1;
            int ret = check(mid);
            if(ret != -1)
            {
                low = mid;
                index = ret;
            }
            else
                high = mid - 1;
        }

        //printf("%d %d\n", index, low);
        return s.substr(index, low);

    }
};