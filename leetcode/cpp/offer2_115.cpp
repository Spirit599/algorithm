// 剑指 Offer II 115. 重建序列
// 拓扑排序
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {

        int n = nums.size();
        int indegress[n + 1];
        memset(indegress, 0, sizeof(indegress));
        vector<int> edges[n + 1];

        for(auto& sequence : sequences)
        {
            for(int i = 0; i + 1 < sequence.size(); ++i)
            {
                edges[sequence[i]].push_back(sequence[i + 1]);
                ++indegress[sequence[i + 1]];
            }
        }

        queue<int> que;
        for(int i = 1; i <= n; ++i)
        {
            if(indegress[i] == 0)
            {
                printf("%d\n", i);
                que.push(i);
            }
        }

        while(!que.empty())
        {
            if(que.size() > 1)
                return false;
            int cur = que.front();
            que.pop();
            for(int next : edges[cur])
            {
                --indegress[next];
                if(indegress[next] == 0)
                    que.push(next);
            }
        }

        return true;


    }
};