class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        function<int(int)> next = [&](int curIndex) -> int {
            return ((curIndex + nums[curIndex]) % n + n) % n;
        };

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == 0)
                continue;
            int slow = i;
            int fast = next(i);
            while(nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0)
            {
                if(slow == fast)
                {
                    if(next(slow) != slow)
                        return true;
                    else
                        break;

                }
                slow = next(slow);
                fast = next(next(fast));
            }

            int clearIndex = i;
            while(nums[clearIndex] * nums[next(clearIndex)] > 0)
            {
                int r = next(clearIndex);
                nums[clearIndex] = 0;
                clearIndex = r;
            }   
        }

        return false;
    }
};