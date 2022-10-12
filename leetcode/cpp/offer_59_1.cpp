// 剑指 Offer 59 - I. 滑动窗口的最大值

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> deq;
        int n = nums.size();
        for(int i = 0; i < k; ++i)
        {
            while(!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();
            deq.push_back(i);
        }

        vector<int> ans({nums[deq.front()]});
        for(int i = k; i < n; ++i)
        {
            while(!deq.empty() && nums[deq.back()] <= nums[i])
                deq.pop_back();
            deq.push_back(i);
            while(deq.front() + k <= i)
                deq.pop_front();
            ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};