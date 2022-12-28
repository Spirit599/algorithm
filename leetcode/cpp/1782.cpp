struct pairHashFunc
{
    template<typename T, typename U>
    size_t operator()(const std::pair<T, U>& p) const {
    return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
    }
};

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {

        
        unordered_map<pair<int, int>, int, pairHashFunc> memo;
        int degress[n + 1];
        int degressCopy[n + 1];
        memset(degress, 0, sizeof(degress));
        memset(degressCopy, 0, sizeof(degressCopy));
        for(auto& edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            ++degress[x];
            ++degress[y];
            if(x > y)
                swap(x, y);
            ++memo[make_pair(x, y)];
        }
        memcpy(degressCopy, degress, sizeof(degressCopy));
        sort(degress, degress + n + 1);

        int querySize = queries.size();
        vector<int> ans(querySize);
        for(int i = 0; i < querySize; ++i)
        {
            int query = queries[i];
            int ll = 1;
            int rr = n;
            int cnt = 0;
            while(ll != rr)
            {
                if(degress[ll] + degress[rr] > query)
                {
                    cnt += (rr - ll);
                    --rr;
                }
                else
                {
                    ++ll;
                }
            }

            for(auto& [k, v] : memo)
            {
                int repe = v;
                auto [x, y] = k;
                
                if(degressCopy[x] + degressCopy[y] > query && degressCopy[x] + degressCopy[y] <= query + repe)
                {
                    --cnt;
                }
            }
            ans[i] = cnt;
        }

        return ans;

    }
};