//Dijkstra
//mlogn 优先队列 邻接表
//单源 最短路径

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int ,int>> edges[n + 1];
        for (int i = 1; i <= n; ++i)
            edges[i].reserve(n + 1);

        for (auto vec : times)
            edges[vec[0]].push_back({vec[1], vec[2]});

        int distance[n + 1];
        memset(distance, 0x3f, sizeof(distance));

        //堆中先距离后节点
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pri_que;
        distance[k] = 0;
        pri_que.emplace(0, k);
        while(!pri_que.empty())
        {
            auto pa = pri_que.top();
            pri_que.pop();

            int cur_distance = pa.first;
            int cur_node = pa.second;

            if(distance[cur_node] < cur_distance)
                continue;

            //ans = max(ans, cur_distance);
            distance[cur_node] = cur_distance;
            for(auto pe : edges[cur_node])
            {
                int next_node = pe.first;
                int cost = pe.second;
                if(distance[next_node] > cur_distance + cost)
                {
                    pri_que.emplace(cur_distance + cost, next_node);
                    distance[next_node] = cur_distance + cost;
                }
            }
        }

        int maxx;
        for(int i = 1; i <= n; ++i)
            maxx = max(maxx, distance[i]);

        return (maxx != 0x3f3f3f3f) ? maxx : -1;
    }
};