//dfs 暴搜
//memo去重
//也可bfs用queue

class Solution {
private:
    unordered_map<int, int> memo;
public:
    int dfs(long long n_copy)
    {
        if(n_copy == 1)
            return 0;
        if(memo.count(n_copy))
            return memo[n_copy];
        else if(n_copy & 1)
        {
            memo[n_copy] = min(dfs(n_copy + 1), dfs(n_copy - 1)) + 1;
            return memo[n_copy];
        }
        else
        {
            memo[n_copy] = dfs(n_copy >> 1) + 1;
            return memo[n_copy];
        }
    }
    int integerReplacement(int n) {

        long long n_copy = n;

        return dfs(n_copy);
    }
};