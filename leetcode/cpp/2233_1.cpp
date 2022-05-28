class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {

        int n = nums.size();
        if(n == 1)
            return k + nums[0];
        
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        while(k)
        {
            int minn = pq.top();
            pq.pop();
            int minn_2 = pq.top();
            pq.pop();

            int dif = min((minn_2 - minn) + 1, k);

            minn += dif;
            k -= dif;

            pq.push(minn);
            pq.push(minn_2);
        }

        long long ans = 1;
        while(!pq.empty())
        {
            cout<<pq.top()<<" ";
            ans = ans * pq.top() % 1000000007;
            pq.pop();
        }


        return ans;
    }
};