// 2366. 将数组排序的最少替换次数

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long ans = 0;
        int n = nums.size();
        int k = nums[n - 1];

        for(int i = n - 2; i >= 0; --i) {
            int cnt = (nums[i] - 1) / k;
            ans += cnt;
            k = nums[i] / (cnt + 1);
        }

        return ans;
    }
};