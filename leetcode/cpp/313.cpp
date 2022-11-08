// 多路归并

typedef pair<long long, int> plli;
class Solution {
public:
    struct info
    {
        long long num;
        int base;
        int ptr;
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        if(n == 1)
            return 1;

        function <bool(const info&, const info&)> cmp = [](const info& info1, const info& info2) {
            return info1.num > info2.num;
        };

        unordered_set<long long> vis;
        priority_queue<info, vector<info>, decltype(cmp)> pq(cmp);

        for(int num : primes)
        {
            vis.insert(num);
            pq.push({num, num, 0});
        }

        long long ans[n];
        ans[0] = 1;
        int cnt = 1;

        while(cnt != n)
        {
            auto cur = pq.top();
            ans[cnt] = cur.num;
            // printf("%lld\n", cur.num);
            pq.pop();
            int ptr = cur.ptr + 1;
            int base = cur.base;
            while(1)
            {
                if(vis.count(ans[ptr] * base) == 0)
                {
                    vis.insert(ans[ptr] * base);
                    pq.push({ans[ptr] * base, base, ptr});
                    break;
                }
                ++ptr;
            }
            ++cnt;
            
        }

        return ans[n - 1];
    }
};