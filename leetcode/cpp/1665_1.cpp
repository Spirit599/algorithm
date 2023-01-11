// 1665. 完成所有任务的最少初始能量
// 贪心

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [&](const vector<int>& v1, const vector<int>& v2) {
            return v2[1] - v2[0] > v1[1] - v1[0];
        });

        int ans = 0;
        int sum = 0;
        for(auto& task : tasks) {
            ans = max(ans, sum + task[1]);
            sum += task[0];
        }
        return ans;
    }
};