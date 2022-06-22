// 1844 · 子数组和为K II

class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the minimum length of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsKII(vector<int> &nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        unordered_map<int, vector<int>> memo;
        memo[0].push_back({-1});

        int pre_sum[n];
        for(int i = 0; i < n; ++i)
        {
        	sum += nums[i];
        	pre_sum[i] = sum;
        	memo[pre_sum[i]].push_back(i);
        }

        int ans = 0x7fffffff;
        for(auto& kav : memo)
        {
        	int key = kav.first;
        	auto it = memo.find(key + k);
        	if(it != memo.end())
        	{
        		int ret = min_diff(kav.second, it->second);
        		ans = min(ans, ret);
        	}
        	// cout<<"key : "<<key<<endl;
        	// for(int num : kav.second)
        	// 	cout<<num<<" ";
        	// cout<<endl;
        }

        if(ans != 0x7fffffff)
        	return ans;
        else
        	return -1;
    }

    int min_diff(const vector<int>& v1, const vector<int>& v2)
    {
    	// if(&v1 == &v2 && v1.size() == 1)
    	// 	return 0x7fffffff;

    	int n1 = v1.size();
    	int n2 = v2.size();
    	int i = 0;
    	int j = 0;
    	int minn = 0x7fffffff;

    	while(i < n1 && j < n2)
    	{
    		if(v1[i] < v2[j])
    		{
    			minn = min(minn, v2[j] - v1[i]);
    			++i;
    		}
    		else if(v1[i] > v2[j])
    		{
    			//minn = min(minn, v1[i] - v2[j]);
    			++j;
    		}
    		else
    		{
    			++i;
    		}
    	}

    	return minn;
    }
};