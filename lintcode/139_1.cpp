//139 · 最接近零的子数组和
//前缀和 差距最小
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        
        vector<int> pre_sum;
        int sum = 0;
        for(auto num : nums)
        {
        	sum += num;
        	pre_sum.push_back(sum);
        }

        vector<pair<int, int>> value_index;
        value_index.push_back(make_pair(0, -1));
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        	value_index.push_back(make_pair(pre_sum[i], i));

        sort(value_index.begin(), value_index.end());

        int minn = value_index[1].first - value_index[0].first;
        int left = min(value_index[1].second, value_index[0].second) + 1;
        int right = max(value_index[1].second, value_index[0].second);
        //cout<<minn<<endl;

        for(int i = 1; i <= n; ++i)
        {
        	int diff = value_index[i].first - value_index[i - 1].first;
        	if(diff < minn)
        	{
        		minn = diff;
        		left = min(value_index[i].second, value_index[i - 1].second) + 1;
        		right = max(value_index[i].second, value_index[i - 1].second);
        	}
        }

        return {left, right};
    }
};