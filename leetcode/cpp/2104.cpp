bool greaterAndEqual(int a, int b) {
    return a >= b;
}
bool lessAndEqual(int a, int b) {
    return a <= b;
}
class Solution {
public:
    long long Helper(vector<int>& nums, bool cmp(int, int)) {

        int n = nums.size();
        int left[n];
        memset(left, -1, sizeof(left));
        int right[n];
        for(int i = 0; i < n; ++i)
            right[i] = n;

        stack<int> sta;
        for(int i = 0; i < n; ++i)
        {
            while(!sta.empty() && cmp(nums[sta.top()], nums[i]))
            {
                right[sta.top()] = i;
                sta.pop();
            }
            if(!sta.empty())
                left[i] = sta.top();
            sta.push(i);
        }

        long long ret = 0;
        for(int i = 0; i < n; ++i)
        {
            ret += 1ll * (i - left[i]) * (right[i] - i) * nums[i];
        }
        return ret;
    }

    long long subArrayRanges(vector<int>& nums) {
        

        return Helper(nums, lessAndEqual) - Helper(nums, greaterAndEqual);
    }
};