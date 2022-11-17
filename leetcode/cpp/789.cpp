class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {

        int dis = abs(target[0]) + abs(target[1]);

        for(auto& ghost : ghosts)
        {
            int ghostDis = abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]);
            if(ghostDis <= dis)
                return false;
        }
        return true;
    }
};