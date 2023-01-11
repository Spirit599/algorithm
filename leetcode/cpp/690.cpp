/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        const int n = 2005;
        vector<int> edges[n];
        int score[n];

        for(auto& em : employees)
        {
            int key = em->id;
            int impo = em->importance;
            vector<int>& sub = em->subordinates;

            score[key] = impo;
            for(int su : sub)
                edges[key].push_back(su);
        }

        function<int(int)> dfs = [&](int cur) -> int {

            int ret = score[cur];
            for(int next : edges[cur])
                ret += dfs(next);
            return ret;
        };

        return dfs(id);

    }
};