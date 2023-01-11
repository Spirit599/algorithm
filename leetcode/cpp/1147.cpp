typedef unsigned long long ull;
class Solution {
public:
    int longestDecomposition(string text) {

        int n = text.size();
        ull preHashCode[n + 1];
        preHashCode[0] = 0;
        ull power[n + 1];
        power[0] = 1;
        ull base = 131;

        for(int i = 0; i < n; ++i)
        {
            preHashCode[i + 1] = preHashCode[i] * base + text[i];
            power[i + 1] = power[i] * base;
        }

        int ans = 0;
        int ll = 0;
        int rr = n;
        int left = 1;
        int right = n - 1;
        while(left <= right)
        {
            if(preHashCode[left] - preHashCode[ll] * power[left - ll] == 
                preHashCode[rr] - preHashCode[right] * power[rr - right])
            {
                ans += 2;
                ll = left;
                rr = right;
                if(ll == rr)
                    return ans;
            }
            ++left;
            --right;
        }

        return ans + 1;

    }
};