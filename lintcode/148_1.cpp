//148 · 颜色分类

class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {

        int p0 = 0;
        int p2 = nums.size() - 1;
        int i = 0;
        while(i <= p2)
        {
            while(i <= p2 && nums[p2] == 2)
                --p2;
            if(i <= p2 && nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if(nums[i] == 0)
            {
                swap(nums[i], nums[p0]);
                ++p0;
            }
            //show(nums, i, p2);
            ++i;
        }
    }

    void show(vector<int>& nums, int i, int p2)
    {
        for(int num : nums)
            cout<<num<<" ";
        cout<<i<<" "<<p2;
        cout<<endl;
    }
};