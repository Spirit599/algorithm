// 53. 最大子数组和

class Solution {
public:
    struct kindOfSum
    {
        int allSum;
        int leftSum;
        int rightSum;
        int conSum;
    };
    int maxSubArray(vector<int>& nums) {

        return get(nums, 0, nums.size() - 1).conSum;
    }

    kindOfSum get(vector<int>& nums, int left, int right)
    {
        if(left == right)
            return {nums[left], nums[left], nums[left], nums[left]};

        int split = (left + right) >> 1;
        kindOfSum lsum = get(nums, left, split);
        kindOfSum rsum = get(nums, split + 1, right);

        return accumulate(lsum, rsum);
    }
    kindOfSum accumulate(kindOfSum lsum, kindOfSum rsum)
    {
        return { lsum.allSum + rsum.allSum,
                max(lsum.leftSum, lsum.allSum + rsum.leftSum),
                max(rsum.rightSum, rsum.allSum + lsum.rightSum),
                max({lsum.conSum, rsum.conSum, lsum.rightSum + rsum.leftSum})
        };
    }
};
