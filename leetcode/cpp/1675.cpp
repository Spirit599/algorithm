class Solution {
public:
    int minimumDeviation(vector<int>& nums) {

        priority_queue<int> pq;
        int minn = INT_MAX;
        for(int num : nums)
        {
            if(num & 1)
            {
                minn = min(minn, num << 1);
                pq.emplace(num << 1);
            }
            else
            {
                pq.emplace(num);
                minn = min(minn, num);
            }
            
        }

        int ans = INT_MAX;

        while(1)
        {
            int k = pq.top();
            ans = min(ans, k - minn);
            if(!(k & 1))
            {
                pq.pop();
                pq.emplace(k >> 1);
                minn = min(minn, k >> 1);
            }
            else break;
        }

        return ans;
    }
};