// 287. 寻找重复数
// 快慢指针 TRICK
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        
        int slow = 0;
        int fast = 0;

        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }

        slow = 0;
        while(1) {
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast)
                return fast;
        }

        return -1;
    }
};