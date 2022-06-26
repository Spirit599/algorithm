// 1862 · 给树浇水的时间

class Solution {
public:
    /**
     * @param father: the father of every node
     * @param time: the time from father[i] to node i
     * @return: time to flower tree
     */
    int timeToFlowerTree(vector<int> &father, vector<int> &time) {

        int n = father.size();
        vector<int> edges[n];
        for(int i = 1; i < n; ++i)
            edges[father[i]].push_back(i);

        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));

        int ans = 0;
        while(!que.empty())
        {
            pair<int, int> cur = que.front();
            que.pop();
            ans = max(ans, cur.second);
            for(int num : edges[cur.first])
            {
                que.push(make_pair(num, cur.second + time[num]));
            }
        }

        return ans;
    }
};