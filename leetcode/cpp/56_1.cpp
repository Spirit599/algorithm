class Solution {
public:
    map<int, int> memo;
    void add(int left, int right) {

        auto it = memo.lower_bound(left);
        while(it != memo.end())
        {
            int nextRight = it->first;
            int nextLeft = it->second;
            //printf("%d %d %d %d\n", left,right,nextLeft,nextRight);
            if(nextLeft > right)
                break;
            left = min(left, nextLeft);
            right = max(right, nextRight);
            //printf("%d %d %d %d\n", left,right,nextLeft,nextRight);
            memo.erase(it++);
        }
        memo[right] = left;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        for(auto& vec : intervals)
        {
            add(vec[0], vec[1]);
        }

        vector<vector<int>> ans;

        for(auto& kv : memo)
        {
            ans.push_back({kv.second, kv.first});
        }
        return ans;
    }
};