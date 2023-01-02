class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());


        int n1 = tasks.size();
        int n2 = workers.size();
        int low = 0;
        int high = min(n1, n2);

        auto check = [&](int mid) -> bool {

            int cnt = pills;
            multiset<int> ws;
            for(int i = 0; i < mid; ++i)
                ws.emplace(workers[i]);

            for(int i = mid - 1; i >= 0; --i)
            {
                auto it = ws.lower_bound(tasks[i]);
                if(it != ws.end())
                {
                    ws.erase(it);
                }
                else if(cnt > 0)
                {
                    auto it1 = ws.lower_bound(tasks[i] - strength);
                    if(it1 == ws.end())
                        return false;
                    ws.erase(it1);
                    --cnt;
                }
                else
                {
                    return false;
                }
            }

            return true;
        };

        while(low != high)
        {
            int mid = (low + high + 1) >> 1;
            if(check(mid))
                low = mid;
            else
                high = mid - 1;
        }


        return low;
    }
};