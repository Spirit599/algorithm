class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    	vector<int> ans;
    	deque<int> deq;
    	int n = nums.size();

    	for(int i = 0; i < k; ++i)
    	{
    		while(!deq.empty() && nums[i] >= nums[deq.back()])
    			deq.pop_back();
    		deq.emplace_back(i);
    	}
    	ans.emplace_back(nums[deq.front()]);

    	for(int i = k; i < n; ++i)
    	{
    		while(!deq.empty() && nums[i] >= nums[deq.back()])
    			deq.pop_back();
    		while(!deq.empty() && deq.front() + k <= i)
    			deq.pop_front();
    		deq.emplace_back(i);
    		ans.emplace_back(nums[deq.front()]);
    	}

    	return ans;
    }
};