// 哈希函数

typedef unsigned long long ull;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        ull hash1[n1 + 1];
        ull power1[n1 + 1];
        hash1[0] = 0;
        power1[0] = 1;
        ull prime = 131;
        for(int i = 0; i < n1; ++i)
        {
            hash1[i + 1] = hash1[i] * prime + nums1[i];
            power1[i + 1] = power1[i] * prime;
        }

        int n2 = nums2.size();
        ull hash2[n2 + 1];
        ull power2[n2 + 1];
        hash2[0] = 0;
        power2[0] = 1;
        for(int i = 0; i < n2; ++i)
        {
            hash2[i + 1] = hash2[i] * prime + nums2[i];
            power2[i + 1] = power2[i] * prime;
        }

        function<bool(int)> check = [&](int mid) -> bool {
            if(mid == 0)
                return true;
            unordered_set<ull> memo;
            for(int i = 1; i + mid - 1 <= n1; ++i)
            {
                int j = i + mid - 1;
                ull hashCode = hash1[j] - hash1[i - 1] * power1[j - i + 1];
                memo.insert(hashCode);
            }
            for(int i = 1; i + mid - 1 <= n2; ++i)
            {
                int j = i + mid - 1;
                ull hashCode = hash2[j] - hash2[i - 1] * power2[j - i + 1];
                if(memo.count(hashCode))
                    return true;
            }
            return false;
        };

        int high = min(n1, n2);
        int low = 0;
        while(low != high)
        {
            int mid = (low + high + 1) >> 1;
            if(check(mid))
            {
                low = mid;
            }
            else
            {
                high = low - 1;
            }
        }


        return low;
    }
};