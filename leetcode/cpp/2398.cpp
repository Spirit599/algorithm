class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        long long sum = 0;
        deque<int> dq;
        int n = chargeTimes.size();
        int ans = 0;
        int left = -1;

        for(int i = 0; i < n; ++i)
        {
            while(!dq.empty() && chargeTimes[dq.back()] < chargeTimes[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            sum += runningCosts[i];

            while(!dq.empty() && chargeTimes[dq.front()] + (i - left) * sum > budget)
            {
                sum -= runningCosts[++left];
                if(dq.front() == left)
                    dq.pop_front();
            }
            ans = max(ans, i - left);
        }

        return ans;


    }
};