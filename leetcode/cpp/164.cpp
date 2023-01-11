// 桶

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();
        if(n < 2)
            return 0;

        int maxx = 0;
        int minn = INT_MAX;
        
        for(int i = 0; i < n; ++i)
        {
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
        }

        int bucketRange = max((maxx - minn) / (n - 1), 1);//平均距离
        int bucketSize = (maxx - minn) / bucketRange + 1;

        // printf("%d %d\n", bucketRange, bucketSize);

        vector<pair<int, int>> buckets(bucketSize, make_pair(-1, -1));
        for(int i = 0; i < n; ++i)
        {
            int index = (nums[i] - minn) / bucketRange;
            if(buckets[index].second != -1)
            {
                buckets[index].first = max(buckets[index].first, nums[i]);
                buckets[index].second = min(buckets[index].second, nums[i]);
            }
            else
            {
                buckets[index] = make_pair(nums[i], nums[i]);
            }
        }

        int ans = 0;
        int preMax = -1;
        for(int i = 0; i < bucketSize; ++i)
        {
            // printf("%d %d\n", buckets[i].first, buckets[i].second);
            if(buckets[i].second == -1)
                continue;
            if(preMax != -1)
                ans = max(ans, buckets[i].second - preMax);
            preMax = buckets[i].first;
        }

        return ans;
    }
};