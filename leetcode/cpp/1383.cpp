class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {


        vector<pair<int, int>> vpii;
        for(int i = 0; i < n; ++i)
            vpii.emplace_back(efficiency[i], speed[i]);
        
        sort(vpii.begin(), vpii.end(), greater<>());
        long long sum = 0;
        long long ans = 0;
        long long eff = 0;
        int mod = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; ++i)
        {
            eff = vpii[i].first;
            sum += vpii[i].second;
            pq.emplace(vpii[i].second);
            ans = max(ans, sum * eff);
        }
        // printf("%d %d\n", eff, sum);

        for(int i = k; i < n; ++i)
        {
            int curSpeed = vpii[i].second;
            eff = vpii[i].first;

            int minSpeed = pq.top();
            pq.pop();

            pq.emplace(curSpeed);
            sum += (curSpeed - minSpeed);
            ans = max(ans, sum * eff);
            // printf("%d %d\n", eff, sum);
        }



        return ans % mod;
    }
};