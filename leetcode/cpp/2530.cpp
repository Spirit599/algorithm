class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());

        while(k--)
        {
            int val = pq.top();
            ans += val;
            pq.pop();

            val = ceil(val / 3.0);
            pq.push(val);
        }

        return ans;

    }
};