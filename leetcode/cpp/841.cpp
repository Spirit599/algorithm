class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        queue<int> que;
        que.push(0);
        vis[0] = true;
        int canVisit = 1;

        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            for(int next : rooms[cur])
            {
                if(!vis[next])
                {
                    ++canVisit;
                    vis[next] = true;
                    que.push(next);
                }
            }
        }

        return canVisit == n;
    }
};