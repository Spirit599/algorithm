class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = amount.size();
        vector<int> edgess[n];

        for(auto& edge : edges)
        {
            edgess[edge[0]].push_back(edge[1]);
            edgess[edge[1]].push_back(edge[0]);
        }

        int clock[n];
        memset(clock, 0x3f, sizeof(clock));
        int inf = 0x3f3f3f3f;

        function<void(int, int, int)> dfsBob = [&](int fa, int cur, int time) {

            clock[cur] = time;
            // printf("%d %d\n", cur, time);
            for(int next : edgess[cur])
            {
                if(next != fa)
                {
                    dfsBob(cur, next, time + 1);
                }
            }
        };

        function<void(int, int)> dfsClearClock = [&](int fa, int cur) {
    
            for(int next : edgess[cur])
            {
                if(next != fa)
                {
                    dfsClearClock(cur, next);
                }
            }
            if(clock[fa] < clock[cur])
                clock[cur] = inf;
            // printf("clock %d %d\n", cur, clock[cur]);
        };
        function<int(int, int, int)> dfs = [&](int fa, int cur, int time) -> int {

            int self;
            // printf("time %d %d %d\n", cur, time, clock[cur]);
            if(time > clock[cur])
                self = 0;
            else if(time < clock[cur])
                self = amount[cur];
            else
                self = amount[cur] / 2;

            if(edgess[cur].size() == 1 && cur != 0)
                return self; // 叶子节点

            int ret = -inf;
            for(int next : edgess[cur])
            {
                if(next != fa)
                {
                    int score = dfs(cur, next, time + 1);
                    // printf("%d %d\n", next, score);
                    ret = max(ret, score);
                }
            }

            return self + ret;
            
        };

        dfsBob(-1, bob, 1);
        dfsClearClock(0, 0);

        return dfs(-1, 0, 1);
    }
};