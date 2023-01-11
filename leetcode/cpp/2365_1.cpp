// 2365. 任务调度器 II

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        unordered_map<int, long long> memo;
        long long curDay = 0;
        int n = tasks.size();
        for (int i = 0; i < n; ++i)
        {
            auto it = memo.find(tasks[i]);
            if(it != memo.end())
            {
                long long pre = it->second;
                curDay = max(curDay + 1, pre + space + 1);
                it->second = curDay;
            }
            else
            {
                ++curDay;
                memo[tasks[i]] = curDay;
            }
        }

        return curDay;
    }
};