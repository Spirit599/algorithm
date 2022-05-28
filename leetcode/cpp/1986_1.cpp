#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_INT (2147483647)

bool cmp(const int& a, const int& b)
{
    return a > b;
}


class Solution {
public:

    int ret = MAX_INT;
    int depth = 0;
    int cur_ret = 1;



    void dfs(vector<int>& tasks, int sessionTime, 
        int visit[], int depth, int remain, int task_size)
    {
        if(cur_ret >= ret)
            return;

        if(depth == task_size)
        {

            ret = min(ret, cur_ret);
            //cout<<"cur_ret"<<cur_ret<<endl;
        }

        bool have_space = false;
        for(int i = 0; i < task_size; ++i)
        {
            if(!visit[i])
            {
                if(tasks[i] <= remain)
                {
                    have_space = true;
                    break;
                }
            }
        }

        if(have_space)
        {
            for (int i = 0; i < task_size; ++i)
            {
                if(visit[i] || ((i > 1) && (tasks[i - 1] == tasks[i]) && (!tasks[i - 1])) )
                    continue;

                if(remain >= tasks[i])
                {
                    remain = remain - tasks[i];
                    visit[i] = true;
                    dfs(tasks, sessionTime, visit,
                        depth + 1, remain, task_size);
                    visit[i] = false;
                    remain = remain + tasks[i];
                }
            }
        }
        else
        {
            for (int i = 0; i < task_size; ++i)
            {
                if(visit[i] || ((i > 1) && (tasks[i - 1] == tasks[i]) && (!tasks[i - 1])) )
                    continue;

                int tmp_remain = remain;
                remain = sessionTime - tasks[i];
                ++cur_ret;
                visit[i] = true;
                dfs(tasks, sessionTime, visit,
                    depth + 1, remain, task_size);
                --cur_ret;
                visit[i] = false;
                remain = tmp_remain;
                break;
            }
        }
    }

    int minSessions(vector<int>& tasks, int sessionTime) {

        int task_size = tasks.size();
        

        sort(tasks.begin(), tasks.end(), cmp);

        // for(auto &i : tasks)
        //     cout<<i<<endl;

        int visit[task_size];
        memset(visit, 0, sizeof(visit));

        int remain = sessionTime;
        dfs(tasks, sessionTime, visit,
            depth, remain, task_size);

        return ret;

    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> tasks{2,2,2,2,1,2,2,2,3,2,3,3};
    int ret = sol.minSessions(tasks, 9);
    cout<<"ret:"<<ret<<"cnt:"<<sol.cnt<<endl;
    return 0;
}