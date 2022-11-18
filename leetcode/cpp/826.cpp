typedef pair<int, int> pii;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int n = difficulty.size();
        vector<pii> work(n);
        for(int i = 0; i < n; ++i)
        {
            work[i] = make_pair(difficulty[i], profit[i]);
        }
        sort(work.begin(), work.end());


        for(int i = 1; i < n; ++i)
        {
            work[i].second = max(work[i].second, work[i - 1].second);
        }

        int ans = 0;
        for(int capa : worker)
        {
            auto it = lower_bound(work.begin(), work.end(), make_pair(capa, 0x3f3f3f3f));
            if(it == work.begin())
                continue;
            --it;
            ans += it->second;
        }

        return ans;



    }
};