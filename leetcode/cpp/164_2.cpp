class Solution {
public:
    int maximumGap(vector<int>& nums) {

    	int n = nums.size();
    	if(n < 2)
            return 0;

    	int maxx = *max_element(nums.begin(), nums.end());
    	int minn = *min_element(nums.begin(), nums.end());


    	int bucketRange = max((maxx - minn) / (n - 1), 1);
    	int bucketSize = (maxx - minn) / bucketRange + 1;

    	vector<pair<int, int>> buckets(bucketSize, make_pair(-1, -1));

    	for(int num : nums)
    	{
    		int idx = (num - minn) / bucketRange;
    		if(buckets[idx].second != -1)
    		{
    			buckets[idx].first = max(buckets[idx].first, num);
    			buckets[idx].second = min(buckets[idx].second, num);
    		}
    		else
    		{
    			buckets[idx] = make_pair(num, num);
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