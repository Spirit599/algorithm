class Solution {
public:
    class comp {
    public:
    bool operator()(const long long& i, const long long& j) {
        return i > j;
    }
};
    int shortestSubarray(vector<int>& nums, int k) {

        map<long long, int> memo;
        int n = nums.size();
        long long sum = 0;

        memo[0] = -1;
        int ans = n + 1;
        for(int i = 0; i < n; ++i)
        {
            sum += nums[i];
            long long key = sum - k;
            map<long long, int>::iterator it;
            while((it = memo.upper_bound(key)) != memo.begin())
            {
                --it;
                printf("%d %d\n",i, it->second );
                ans = min(ans, i - it->second);
                memo.erase(it);
            }
            memo[sum] = i;
        }
        if(ans != n + 1)
            return ans;
        else
            return -1;
    }
};