//616 · 课程表 II

class Solution {
public:
    /**
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        
        bool visited[numCourses + 5];
        memset(visited, 0, sizeof(visited));
        int cur_course_pre[numCourses + 5];
        memset(cur_course_pre, 0, sizeof(cur_course_pre));
        int need_pre[numCourses + 5];
        memset(need_pre, 0, sizeof(need_pre));

        vector<int> edges[numCourses + 5];
        for(auto& prerequisite : prerequisites)
        {
            ++need_pre[prerequisite[0]];
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }
     
        vector<int> ans;
        queue<int> que;
        int num = 0;

        for(int i = 0; i < numCourses; ++i)
        {
            if(need_pre[i] == 0)
            {
                que.push(i);
                ans.push_back(i);
                ++num;
                visited[i] = true;
                //printf("k = %d\n", i);
            }
        }


        while(!que.empty())
        {
            if(num == numCourses)
                return ans;
            int cur = que.front();
            que.pop();
            for(int son : edges[cur])
            {
                if(!visited[son])
                {
                    ++cur_course_pre[son];
                    if(cur_course_pre[son] == need_pre[son])
                    {
                        que.push(son);
                        visited[son] = true;
                        ++num;
                        ans.push_back(son);
                    }
                    //printf("son = %d\n", son);    
                }
            }
        }

        vector<int> ret;
        return ret;


    }
};