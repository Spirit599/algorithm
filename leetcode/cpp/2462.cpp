class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        auto cmp = [&](const pair<int, bool>& i, const pair<int, bool>& j) {

            if(costs[i.first] != costs[j.first])
                return costs[i.first] > costs[j.first];
            else
                return i.first > j.first;
        };

        priority_queue<pair<int, bool>, vector<pair<int, bool>>, decltype(cmp)> pq(cmp);

        int n = costs.size();
        int right = costs.size();
        int left = -1;

        
        for(int i = 0; i < candidates; ++i)
        {
            ++left;
            pq.push(make_pair(left, true));
        }
        for(int i = 0; i < candidates; ++i)
        {
            --right;
            if(right == left)
                break;
            pq.push(make_pair(right, false));
        }

        long long ans = 0;
        while(k--)
        {
            auto cur = pq.top();
            pq.pop();
            ans += costs[cur.first];

            if(left + 1 < right)
            {
                if(cur.second)
                {
                    pq.push(make_pair(++left, true));
                }
                else
                {
                    pq.push(make_pair(--right, false));
                }
            }
        }

        return ans;
    }
};