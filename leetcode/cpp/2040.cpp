
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
        vector<long long> vv;
        int n1 = nums1.size();
        long long a1 = nums1[0];
        long long b1 = nums1[n1 - 1];
        int n2 = nums2.size();
        long long a2 = nums2[0];
        long long b2 = nums2[n2 - 1];

        long long low = min({a1 * a2, a1 * b2, a2 * b1, b2 * b1});
        long long high = max({a1 * a2, a1 * b2, a2 * b1, b2 * b1});

        k = 1ll*n1 * n2 - k + 1;

        auto check = [&](long long mid) -> bool {

            long long cnt = 0;
            for(int x : nums1)
            {
                if(x > 0)
                {
                    long long val = ceil(1.0 * mid / x);
                    if(val > nums2.back())
                        continue;
                    auto it = lower_bound(nums2.begin(), nums2.end(), val);
                    cnt += nums2.end() - it;
                }
                else if(x < 0)
                {
                    long long val = floor(1.0 * mid / x);
                    if(val < nums2.front())
                        continue;
                    auto it = upper_bound(nums2.begin(), nums2.end(), val);
                    cnt += it - nums2.begin();
                }
                else
                {
                    if(mid <= 0)
                        cnt += n2;
                }
                if(cnt >= k)
                    return true;
            }
            return false;
        };

        


        while(low != high)
        {
            long long mid = (low + high + 1) >> 1;
            if(check(mid))
                low = mid;
            else
                high = mid - 1;
        }


        return low;
    }
};