typedef pair<int, int> pii;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        vector<pii> nums(n);
        for(int i = 0; i < n; ++i)
        {
            nums[i] = make_pair(nums2[i], nums1[i]);
        }
        sort(nums.begin(), nums.end(), greater<>());

        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < k; ++i)
        {
            pq.emplace(nums[i].second);
            sum += nums[i].second;
        }

        long long ans = sum * nums[k - 1].first;
        for(int i = k; i < n; ++i)
        {
            int val = nums[i].second;
            pq.emplace(val);
            sum += val;
            int rmVal = pq.top();
            pq.pop();
            sum -= rmVal;
            ans = max(ans, sum * nums[i].first);
        }
        return ans;
    }
};