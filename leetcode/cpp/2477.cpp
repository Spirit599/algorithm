typedef pair<int, long long> pill;
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size() + 1;
        vector<int> edges[n];

        for(vector<int>& road : roads)
        {
            edges[road[0]].push_back(road[1]);
            edges[road[1]].push_back(road[0]);
        }


        function<pill(int, int)> dfs = [&](int cur, int fa) -> pill {

            int num = 1;
            long long oil = 0;

            for(int next : edges[cur])
            {
                if(fa != next)
                {
                    pill ret = dfs(next, cur);
                    int sonNum = ret.first;
                    long long sonOil = ret.second;

                    int cars;
                    if(sonNum % seats == 0)
                        cars = sonNum / seats;
                    else
                        cars = sonNum / seats + 1;

                    num += sonNum;
                    oil += sonOil + cars;
                }
            }

            return make_pair(num, oil);
        };

        return dfs(0, -1).second;
    }
};