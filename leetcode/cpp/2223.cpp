typedef unsigned long long ull;
class Solution {
public:
    long long sumScores(string s) {
        
        long long ans = 0;
        int n = s.size();
        ull hashCode[n + 1];
        hashCode[0] = 0;
        ull base = 131;
        ull power[n + 1];
        power[0] = 1;

        for(int i = 0; i < n; ++i)
        {
            hashCode[i + 1] = hashCode[i] * base + s[i];
            power[i + 1] = power[i] * base;
        }


        for(int len = 1; len <= n; ++len)
        {
            int s1 = 0;
            int s2 = n - len;

            int low = 0;
            int high = len;
            while(low != high)
            {
                int mid = (low + high + 1) >> 1;
                int e1 = s1 + mid - 1;
                int e2 = s2 + mid - 1;
                if(hashCode[e1 + 1] - hashCode[s1] * power[mid] == hashCode[e2 + 1] - hashCode[s2] * power[mid])
                    low = mid;
                else
                    high = mid - 1;
            }
            ans += low;
        }

        return ans;

    }
};