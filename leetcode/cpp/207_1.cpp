// 207. 课程表

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {



        vector<int> edges[numCourses];
        int pre_num[numCourses];
        memset(pre_num, 0, sizeof(pre_num));
        int pre_cnt[numCourses];
        memset(pre_cnt, 0, sizeof(pre_cnt));

        for(auto& vec : prerequisites)
        {
            edges[vec[1]].push_back(vec[0]);
            ++pre_num[vec[0]];
        }

        bool visited[numCourses];
        memset(visited, 0, sizeof(visited));
        int have_learned = 0;
        queue<int> que;

        for(int i = 0; i < numCourses; ++i)
        {
            if(pre_num[i] == 0)
            {
                ++have_learned;
                if(have_learned == numCourses)
                    return true;
                visited[i] = true;
                que.push(i);
            }
        }

        while(!que.empty())
        {
            int cur = que.front();
            cout<<cur<<endl;
            que.pop();

            for(int next : edges[cur])
            {
                ++pre_cnt[next];
                if(pre_num[next] == pre_cnt[next])
                {
                    que.push(next);
                    ++have_learned;
                    if(have_learned == numCourses)
                        return true;
                }
            }
        }

        return false;

    }
};