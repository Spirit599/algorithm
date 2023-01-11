class Solution {
public:
    vector<string> addOperators(string num, int target) {

        vector<string> ans;
        int n = num.size();

        function<void(string&, int, long long, long long)> dfs = [&](string& cur, int depth, long long val, long long lastMul) {

            if(depth == n)
            {
                if(val == target)
                    ans.push_back(cur);
                return ;
            }

            long long v = 0;
            for(int i = depth; i < n; ++i)
            {
                v = v * 10 + num[i] - '0';
                string vStr = to_string(v);
                int orgrinSize = cur.size();
                
                if(depth != 0)
                {
                    // printf("%d %d\n", val, v);
                    // cout<<cur<<endl;
                    cur.push_back('+');
                    cur += vStr;
                    dfs(cur, i + 1, val + v, v);
                    cur.resize(orgrinSize);

                    cur.push_back('-');
                    cur += vStr;
                    dfs(cur, i + 1, val - v, -v);
                    cur.resize(orgrinSize);

                    cur.push_back('*');
                    cur += vStr;
                    dfs(cur, i + 1, val - lastMul + lastMul * v, lastMul * v);
                    cur.resize(orgrinSize);
                }
                else
                {
                    cur += vStr;
                    dfs(cur, i + 1, v, v);
                    cur.resize(orgrinSize);
                }
                if(v == 0)
                    break;
            }
        };

        string cur;
        dfs(cur, 0, 0, 0);

        return ans;
    }
};