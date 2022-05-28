class Solution {
private:
    set<pair<int, int>> hash_table___;
public:
    bool check(int x1, int x2, int y1, int y2)
    {

        for(int i = x1; i <= x2; ++i)
        {
            for(int j = y1; j <= y2; ++j)
            {
                if(hash_table___.find(make_pair(i, j)) == hash_table___.end())
                {
                    return false;
                }
            }
        }

        return true;
    }


    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        int ans = 0;
        
        for(auto &vec : dig)
        {
            hash_table___.insert(make_pair(vec[0], vec[1]));
        }

        for(auto &art : artifacts)
        {
           if(check(art[0], art[2], art[1], art[3]))
                ++ans;
        }

        return ans;
    }
};