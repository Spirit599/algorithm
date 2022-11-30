class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        int n = quality.size();
        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int a, int b) {return wage[a] * quality[b] < wage[b] * quality[a];});

        int sum = 0;
        priority_queue<int> que;
        for(int i = 0; i < k; ++i)
        {
            sum += quality[idx[i]];
            que.emplace(quality[idx[i]]);
        }

        double ans = 1.0 * sum * wage[idx[k - 1]] / quality[idx[k - 1]];
        for(int i = k; i < n; ++i)
        {
            int curQ = quality[idx[i]];
            if(curQ < que.top())
            {
                sum -= que.top() - curQ;
                que.pop();
                que.emplace(curQ);
                ans = min(ans, 1.0 * sum * wage[idx[i]] / quality[idx[i]]);
            }
        }

        return ans;
    }
};