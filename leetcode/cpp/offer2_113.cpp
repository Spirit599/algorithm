class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> edges[numCourses];
        int indegress[numCourses];
        memset(indegress, 0, sizeof(indegress));

        for(auto& prerequisite : prerequisites)
        {
            edges[prerequisite[1]].push_back(prerequisite[0]);
            ++indegress[prerequisite[0]];
        }

        queue<int> que;
        vector<int> ans;
        for(int i = 0; i < numCourses; ++i)
        {
            if(indegress[i] == 0)
            {
                que.push(i);
                ans.push_back(i);
            }
        }

        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            for(int next : edges[cur])
            {
                --indegress[next];
                if(indegress[next] == 0)
                {
                    que.push(next);
                    ans.push_back(next);
                }
            }
        }

        if(ans.size() == numCourses)
            return ans;
        else
            return vector<int>();
    }
};