// 双端队列

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> deq;
        vector<int> ans;

        for(int i = 0; i < k; ++i)
        {
            while(!deq.empty() && nums[i] > nums[deq.back()])
            {
                deq.pop_back();
            }
            deq.push_back(i);
        }

        ans.push_back(nums[deq.front()]);

        int n = nums.size();
        for (int i = k; i < n; ++i)
        {
            while(!deq.empty() && nums[i] > nums[deq.back()])
            {
                deq.pop_back();
            }
            deq.push_back(i);

            while(deq.front() + k <= i)
                deq.pop_front();

            ans.push_back(nums[deq.front()]);
        }

        return ans;

    }
};