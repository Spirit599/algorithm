class Solution {
public:
    int getKthMagicNumber(int k) {

        unordered_set<long long> vis;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        vis.insert(1);

        while(1) {
            long long cur = pq.top();
            printf("%d\n", cur);
            pq.pop();
            --k;
            if(k == 0)
                return cur;
            if(!vis.count(3 * cur))
            {
                vis.insert(3 * cur);
                pq.push(3 * cur);
            }
            if(!vis.count(5 * cur))
            {
                vis.insert(5 * cur);
                pq.push(5 * cur);
            }
            if(!vis.count(7 * cur))
            {
                vis.insert(7 * cur);
                pq.push(7 * cur);
            }
        }

        return 0;
    }
};