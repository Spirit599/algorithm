class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        

        long long high = LONG_MAX - 1;
        long long low = 0;
        int n = stations.size();
        vector<long long> preSum(n + 1);
        preSum[0] = 0;
        for(int i = 1; i <= n; ++i)
            preSum[i] = preSum[i - 1] + stations[i - 1];

        vector<long long> powers(n);
        for(int i = 0; i < n; ++i)
        {
            int right = i + r;
            int left = i - r;
            if(left < 0)
                left = 0;
            if(right > n - 1)
                right = n - 1;

            long long cur = preSum[right + 1] - preSum[left];
            powers[i] = cur;
        }

        auto check = [&](long long mid) -> bool {

            long long add = 0;
            vector<int> diff(n, 0);
            int remain = k;

            for(int i = 0; i < n; ++i)
            {
                add += diff[i];
                long long cur = powers[i] + add;
                long long detal = max(mid - cur, 0ll);
                if(detal == 0)
                    continue;
                if(detal > remain)
                    return false;
                remain -= detal;
                add += detal;
                int rmIdx = i + 2 * r + 1;
                if(rmIdx < n)
                    diff[rmIdx] -= detal;
            }

            return true;
        };

        while(low != high)
        {
            long long mid = (low + high + 1) / 2;
            if(check(mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};